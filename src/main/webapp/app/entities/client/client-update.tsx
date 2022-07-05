import React, { useState, useEffect } from 'react';
import { Link, RouteComponentProps } from 'react-router-dom';
import { Button, Row, Col, FormText, UncontrolledTooltip } from 'reactstrap';
import { isNumber, Translate, translate, ValidatedField, ValidatedForm } from 'react-jhipster';
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome';

import { convertDateTimeFromServer, convertDateTimeToServer, displayDefaultDateTime } from 'app/shared/util/date-utils';
import { mapIdList } from 'app/shared/util/entity-utils';
import { useAppDispatch, useAppSelector } from 'app/config/store';

import { IClient } from 'app/shared/model/client.model';
import { LifecycleStatus } from 'app/shared/model/enumerations/lifecycle-status.model';
import { getEntity, updateEntity, createEntity, reset } from './client.reducer';

export const ClientUpdate = (props: RouteComponentProps<{ id: string }>) => {
  const dispatch = useAppDispatch();

  const [isNew] = useState(!props.match.params || !props.match.params.id);

  const clientEntity = useAppSelector(state => state.client.entity);
  const loading = useAppSelector(state => state.client.loading);
  const updating = useAppSelector(state => state.client.updating);
  const updateSuccess = useAppSelector(state => state.client.updateSuccess);
  const lifecycleStatusValues = Object.keys(LifecycleStatus);
  const handleClose = () => {
    props.history.push('/client' + props.location.search);
  };

  useEffect(() => {
    if (isNew) {
      dispatch(reset());
    } else {
      dispatch(getEntity(props.match.params.id));
    }
  }, []);

  useEffect(() => {
    if (updateSuccess) {
      handleClose();
    }
  }, [updateSuccess]);

  const saveEntity = values => {
    const entity = {
      ...clientEntity,
      ...values,
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
          ...clientEntity,
        };

  return (
    <div>
      <Row className="justify-content-center">
        <Col md="8">
          <h2 id="contractTooolApp.client.home.createOrEditLabel" data-cy="ClientCreateUpdateHeading">
            <Translate contentKey="contractTooolApp.client.home.createOrEditLabel">Create or edit a Client</Translate>
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
                  id="client-id"
                  label={translate('contractTooolApp.client.id')}
                  validate={{ required: true }}
                />
              ) : null}
              <ValidatedField
                label={translate('contractTooolApp.client.name')}
                id="client-name"
                name="name"
                data-cy="name"
                type="text"
                validate={{
                  required: { value: true, message: translate('entity.validation.required') },
                  minLength: { value: 1, message: translate('entity.validation.minlength', { min: 1 }) },
                  maxLength: { value: 50, message: translate('entity.validation.maxlength', { max: 50 }) },
                }}
              />
              <UncontrolledTooltip target="nameLabel">
                <Translate contentKey="contractTooolApp.client.help.name" />
              </UncontrolledTooltip>
              <ValidatedField
                label={translate('contractTooolApp.client.salesManagerId')}
                id="client-salesManagerId"
                name="salesManagerId"
                data-cy="salesManagerId"
                type="text"
                validate={{
                  required: { value: true, message: translate('entity.validation.required') },
                  validate: v => isNumber(v) || translate('entity.validation.number'),
                }}
              />
              <UncontrolledTooltip target="salesManagerIdLabel">
                <Translate contentKey="contractTooolApp.client.help.salesManagerId" />
              </UncontrolledTooltip>
              <ValidatedField
                label={translate('contractTooolApp.client.countryId')}
                id="client-countryId"
                name="countryId"
                data-cy="countryId"
                type="text"
                validate={{
                  required: { value: true, message: translate('entity.validation.required') },
                }}
              />
              <UncontrolledTooltip target="countryIdLabel">
                <Translate contentKey="contractTooolApp.client.help.countryId" />
              </UncontrolledTooltip>
              <ValidatedField
                label={translate('contractTooolApp.client.partnerStatus')}
                id="client-partnerStatus"
                name="partnerStatus"
                data-cy="partnerStatus"
                check
                type="checkbox"
              />
              <UncontrolledTooltip target="partnerStatusLabel">
                <Translate contentKey="contractTooolApp.client.help.partnerStatus" />
              </UncontrolledTooltip>
              <ValidatedField
                label={translate('contractTooolApp.client.contactPerson')}
                id="client-contactPerson"
                name="contactPerson"
                data-cy="contactPerson"
                type="text"
                validate={{
                  required: { value: true, message: translate('entity.validation.required') },
                }}
              />
              <UncontrolledTooltip target="contactPersonLabel">
                <Translate contentKey="contractTooolApp.client.help.contactPerson" />
              </UncontrolledTooltip>
              <ValidatedField
                label={translate('contractTooolApp.client.contractEmail')}
                id="client-contractEmail"
                name="contractEmail"
                data-cy="contractEmail"
                type="text"
                validate={{
                  required: { value: true, message: translate('entity.validation.required') },
                }}
              />
              <UncontrolledTooltip target="contractEmailLabel">
                <Translate contentKey="contractTooolApp.client.help.contractEmail" />
              </UncontrolledTooltip>
              <ValidatedField
                label={translate('contractTooolApp.client.industryId')}
                id="client-industryId"
                name="industryId"
                data-cy="industryId"
                type="text"
              />
              <UncontrolledTooltip target="industryIdLabel">
                <Translate contentKey="contractTooolApp.client.help.industryId" />
              </UncontrolledTooltip>
              <ValidatedField
                label={translate('contractTooolApp.client.signer')}
                id="client-signer"
                name="signer"
                data-cy="signer"
                type="text"
              />
              <UncontrolledTooltip target="signerLabel">
                <Translate contentKey="contractTooolApp.client.help.signer" />
              </UncontrolledTooltip>
              <ValidatedField
                label={translate('contractTooolApp.client.signerPosition')}
                id="client-signerPosition"
                name="signerPosition"
                data-cy="signerPosition"
                type="text"
              />
              <UncontrolledTooltip target="signerPositionLabel">
                <Translate contentKey="contractTooolApp.client.help.signerPosition" />
              </UncontrolledTooltip>
              <ValidatedField
                label={translate('contractTooolApp.client.legalAddress')}
                id="client-legalAddress"
                name="legalAddress"
                data-cy="legalAddress"
                type="text"
              />
              <UncontrolledTooltip target="legalAddressLabel">
                <Translate contentKey="contractTooolApp.client.help.legalAddress" />
              </UncontrolledTooltip>
              <ValidatedField
                label={translate('contractTooolApp.client.registrationNumber')}
                id="client-registrationNumber"
                name="registrationNumber"
                data-cy="registrationNumber"
                type="text"
              />
              <UncontrolledTooltip target="registrationNumberLabel">
                <Translate contentKey="contractTooolApp.client.help.registrationNumber" />
              </UncontrolledTooltip>
              <ValidatedField
                label={translate('contractTooolApp.client.baseOfActivityId')}
                id="client-baseOfActivityId"
                name="baseOfActivityId"
                data-cy="baseOfActivityId"
                type="text"
              />
              <UncontrolledTooltip target="baseOfActivityIdLabel">
                <Translate contentKey="contractTooolApp.client.help.baseOfActivityId" />
              </UncontrolledTooltip>
              <ValidatedField
                label={translate('contractTooolApp.client.vatNumber')}
                id="client-vatNumber"
                name="vatNumber"
                data-cy="vatNumber"
                type="text"
              />
              <UncontrolledTooltip target="vatNumberLabel">
                <Translate contentKey="contractTooolApp.client.help.vatNumber" />
              </UncontrolledTooltip>
              <ValidatedField
                label={translate('contractTooolApp.client.bankName')}
                id="client-bankName"
                name="bankName"
                data-cy="bankName"
                type="text"
              />
              <UncontrolledTooltip target="bankNameLabel">
                <Translate contentKey="contractTooolApp.client.help.bankName" />
              </UncontrolledTooltip>
              <ValidatedField
                label={translate('contractTooolApp.client.bankAddress')}
                id="client-bankAddress"
                name="bankAddress"
                data-cy="bankAddress"
                type="text"
              />
              <UncontrolledTooltip target="bankAddressLabel">
                <Translate contentKey="contractTooolApp.client.help.bankAddress" />
              </UncontrolledTooltip>
              <ValidatedField
                label={translate('contractTooolApp.client.swiftCode')}
                id="client-swiftCode"
                name="swiftCode"
                data-cy="swiftCode"
                type="text"
              />
              <UncontrolledTooltip target="swiftCodeLabel">
                <Translate contentKey="contractTooolApp.client.help.swiftCode" />
              </UncontrolledTooltip>
              <ValidatedField
                label={translate('contractTooolApp.client.ibanCode')}
                id="client-ibanCode"
                name="ibanCode"
                data-cy="ibanCode"
                type="text"
              />
              <UncontrolledTooltip target="ibanCodeLabel">
                <Translate contentKey="contractTooolApp.client.help.ibanCode" />
              </UncontrolledTooltip>
              <ValidatedField
                label={translate('contractTooolApp.client.lifecycleStatus')}
                id="client-lifecycleStatus"
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
                <Translate contentKey="contractTooolApp.client.help.lifecycleStatus" />
              </UncontrolledTooltip>
              <Button tag={Link} id="cancel-save" data-cy="entityCreateCancelButton" to="/client" replace color="info">
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

export default ClientUpdate;
