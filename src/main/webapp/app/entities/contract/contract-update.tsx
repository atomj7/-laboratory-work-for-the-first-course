import React, { useState, useEffect } from 'react';
import { Link, RouteComponentProps } from 'react-router-dom';
import { Button, Row, Col, FormText, UncontrolledTooltip } from 'reactstrap';
import { isNumber, Translate, translate, ValidatedField, ValidatedForm } from 'react-jhipster';
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome';

import { convertDateTimeFromServer, convertDateTimeToServer, displayDefaultDateTime } from 'app/shared/util/date-utils';
import { mapIdList } from 'app/shared/util/entity-utils';
import { useAppDispatch, useAppSelector } from 'app/config/store';

import { IClient } from 'app/shared/model/client.model';
import { getEntities as getClients } from 'app/entities/client/client.reducer';
import { IContract } from 'app/shared/model/contract.model';
import { LifecycleStatus } from 'app/shared/model/enumerations/lifecycle-status.model';
import { getEntity, updateEntity, createEntity, reset } from './contract.reducer';

export const ContractUpdate = (props: RouteComponentProps<{ id: string }>) => {
  const dispatch = useAppDispatch();

  const [isNew] = useState(!props.match.params || !props.match.params.id);

  const clients = useAppSelector(state => state.client.entities);
  const contractEntity = useAppSelector(state => state.contract.entity);
  const loading = useAppSelector(state => state.contract.loading);
  const updating = useAppSelector(state => state.contract.updating);
  const updateSuccess = useAppSelector(state => state.contract.updateSuccess);
  const lifecycleStatusValues = Object.keys(LifecycleStatus);
  const handleClose = () => {
    props.history.push('/contract' + props.location.search);
  };

  useEffect(() => {
    if (isNew) {
      dispatch(reset());
    } else {
      dispatch(getEntity(props.match.params.id));
    }

    dispatch(getClients({}));
  }, []);

  useEffect(() => {
    if (updateSuccess) {
      handleClose();
    }
  }, [updateSuccess]);

  const saveEntity = values => {
    const entity = {
      ...contractEntity,
      ...values,
      client: clients.find(it => it.id.toString() === values.client.toString()),
    };

    if (isNew) {
      dispatch(createEntity(entity));
    } else {
      dispatch(updateEntity(entity));
    }
  };

  const defaultValues = () =>
    isNew
      ? {}
      : {
          lifecycleStatus: 'ACTUAL',
          ...contractEntity,
          client: contractEntity?.client?.id,
        };

  return (
    <div>
      <Row className="justify-content-center">
        <Col md="8">
          <h2 id="contractTooolApp.contract.home.createOrEditLabel" data-cy="ContractCreateUpdateHeading">
            <Translate contentKey="contractTooolApp.contract.home.createOrEditLabel">Create or edit a Contract</Translate>
          </h2>
        </Col>
      </Row>
      <Row className="justify-content-center">
        <Col md="8">
          {loading ? (
            <p>Loading...</p>
          ) : (
            <ValidatedForm defaultValues={defaultValues()} onSubmit={saveEntity}>
              {!isNew ? (
                <ValidatedField
                  name="id"
                  required
                  readOnly
                  id="contract-id"
                  label={translate('contractTooolApp.contract.id')}
                  validate={{ required: true }}
                />
              ) : null}
              <ValidatedField
                label={translate('contractTooolApp.contract.cipher')}
                id="contract-cipher"
                name="cipher"
                data-cy="cipher"
                type="text"
                validate={{
                  required: { value: true, message: translate('entity.validation.required') },
                }}
              />
              <UncontrolledTooltip target="cipherLabel">
                <Translate contentKey="contractTooolApp.contract.help.cipher" />
              </UncontrolledTooltip>
              <ValidatedField
                label={translate('contractTooolApp.contract.providerId')}
                id="contract-providerId"
                name="providerId"
                data-cy="providerId"
                type="text"
                validate={{
                  required: { value: true, message: translate('entity.validation.required') },
                }}
              />
              <UncontrolledTooltip target="providerIdLabel">
                <Translate contentKey="contractTooolApp.contract.help.providerId" />
              </UncontrolledTooltip>
              <ValidatedField
                label={translate('contractTooolApp.contract.typeId')}
                id="contract-typeId"
                name="typeId"
                data-cy="typeId"
                type="text"
              />
              <UncontrolledTooltip target="typeIdLabel">
                <Translate contentKey="contractTooolApp.contract.help.typeId" />
              </UncontrolledTooltip>
              <ValidatedField
                label={translate('contractTooolApp.contract.sum')}
                id="contract-sum"
                name="sum"
                data-cy="sum"
                type="text"
                validate={{
                  required: { value: true, message: translate('entity.validation.required') },
                  validate: v => isNumber(v) || translate('entity.validation.number'),
                }}
              />
              <UncontrolledTooltip target="sumLabel">
                <Translate contentKey="contractTooolApp.contract.help.sum" />
              </UncontrolledTooltip>
              <ValidatedField
                label={translate('contractTooolApp.contract.positionCount')}
                id="contract-positionCount"
                name="positionCount"
                data-cy="positionCount"
                type="text"
                validate={{
                  required: { value: true, message: translate('entity.validation.required') },
                  validate: v => isNumber(v) || translate('entity.validation.number'),
                }}
              />
              <UncontrolledTooltip target="positionCountLabel">
                <Translate contentKey="contractTooolApp.contract.help.positionCount" />
              </UncontrolledTooltip>
              <ValidatedField
                label={translate('contractTooolApp.contract.currencyId')}
                id="contract-currencyId"
                name="currencyId"
                data-cy="currencyId"
                type="text"
                validate={{
                  required: { value: true, message: translate('entity.validation.required') },
                }}
              />
              <UncontrolledTooltip target="currencyIdLabel">
                <Translate contentKey="contractTooolApp.contract.help.currencyId" />
              </UncontrolledTooltip>
              <ValidatedField
                label={translate('contractTooolApp.contract.paymentTerm')}
                id="contract-paymentTerm"
                name="paymentTerm"
                data-cy="paymentTerm"
                type="text"
                validate={{
                  required: { value: true, message: translate('entity.validation.required') },
                  validate: v => isNumber(v) || translate('entity.validation.number'),
                }}
              />
              <UncontrolledTooltip target="paymentTermLabel">
                <Translate contentKey="contractTooolApp.contract.help.paymentTerm" />
              </UncontrolledTooltip>
              <ValidatedField
                label={translate('contractTooolApp.contract.paymentTermTypeId')}
                id="contract-paymentTermTypeId"
                name="paymentTermTypeId"
                data-cy="paymentTermTypeId"
                type="text"
                validate={{
                  required: { value: true, message: translate('entity.validation.required') },
                }}
              />
              <UncontrolledTooltip target="paymentTermTypeIdLabel">
                <Translate contentKey="contractTooolApp.contract.help.paymentTermTypeId" />
              </UncontrolledTooltip>
              <ValidatedField
                label={translate('contractTooolApp.contract.startDate')}
                id="contract-startDate"
                name="startDate"
                data-cy="startDate"
                type="date"
                validate={{
                  required: { value: true, message: translate('entity.validation.required') },
                }}
              />
              <UncontrolledTooltip target="startDateLabel">
                <Translate contentKey="contractTooolApp.contract.help.startDate" />
              </UncontrolledTooltip>
              <ValidatedField
                label={translate('contractTooolApp.contract.finishDate')}
                id="contract-finishDate"
                name="finishDate"
                data-cy="finishDate"
                type="date"
                validate={{
                  required: { value: true, message: translate('entity.validation.required') },
                }}
              />
              <UncontrolledTooltip target="finishDateLabel">
                <Translate contentKey="contractTooolApp.contract.help.finishDate" />
              </UncontrolledTooltip>
              <ValidatedField
                label={translate('contractTooolApp.contract.statusId')}
                id="contract-statusId"
                name="statusId"
                data-cy="statusId"
                type="text"
                validate={{
                  required: { value: true, message: translate('entity.validation.required') },
                }}
              />
              <ValidatedField
                label={translate('contractTooolApp.contract.link')}
                id="contract-link"
                name="link"
                data-cy="link"
                type="text"
              />
              <UncontrolledTooltip target="linkLabel">
                <Translate contentKey="contractTooolApp.contract.help.link" />
              </UncontrolledTooltip>
              <ValidatedField
                label={translate('contractTooolApp.contract.lifecycleStatus')}
                id="contract-lifecycleStatus"
                name="lifecycleStatus"
                data-cy="lifecycleStatus"
                type="select"
              >
                {lifecycleStatusValues.map(lifecycleStatus => (
                  <option value={lifecycleStatus} key={lifecycleStatus}>
                    {translate('contractTooolApp.LifecycleStatus.' + lifecycleStatus)}
                  </option>
                ))}
              </ValidatedField>
              <UncontrolledTooltip target="lifecycleStatusLabel">
                <Translate contentKey="contractTooolApp.contract.help.lifecycleStatus" />
              </UncontrolledTooltip>
              <ValidatedField
                id="contract-client"
                name="client"
                data-cy="client"
                label={translate('contractTooolApp.contract.client')}
                type="select"
              >
                <option value="" key="0" />
                {clients
                  ? clients.map(otherEntity => (
                      <option value={otherEntity.id} key={otherEntity.id}>
                        {otherEntity.id}
                      </option>
                    ))
                  : null}
              </ValidatedField>
              <Button tag={Link} id="cancel-save" data-cy="entityCreateCancelButton" to="/contract" replace color="info">
                <FontAwesomeIcon icon="arrow-left" />
                &nbsp;
                <span className="d-none d-md-inline">
                  <Translate contentKey="entity.action.back">Back</Translate>
                </span>
              </Button>
              &nbsp;
              <Button color="primary" id="save-entity" data-cy="entityCreateSaveButton" type="submit" disabled={updating}>
                <FontAwesomeIcon icon="save" />
                &nbsp;
                <Translate contentKey="entity.action.save">Save</Translate>
              </Button>
            </ValidatedForm>
          )}
        </Col>
      </Row>
    </div>
  );
};

export default ContractUpdate;
