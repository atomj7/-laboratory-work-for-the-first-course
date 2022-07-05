import React, { useEffect } from 'react';
import { Link, RouteComponentProps } from 'react-router-dom';
import { Button, UncontrolledTooltip, Row, Col } from 'reactstrap';
import { Translate } from 'react-jhipster';
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome';

import { APP_DATE_FORMAT, APP_LOCAL_DATE_FORMAT } from 'app/config/constants';
import { useAppDispatch, useAppSelector } from 'app/config/store';

import { getEntity } from './contract-position.reducer';

export const ContractPositionDetail = (props: RouteComponentProps<{ id: string }>) => {
  const dispatch = useAppDispatch();

  useEffect(() => {
    dispatch(getEntity(props.match.params.id));
  }, []);

  const contractPositionEntity = useAppSelector(state => state.contractPosition.entity);
  return (
    <Row>
      <Col md="8">
        <h2 data-cy="contractPositionDetailsHeading">
          <Translate contentKey="contractTooolApp.contractPosition.detail.title">ContractPosition</Translate>
        </h2>
        <dl className="jh-entity-details">
          <dt>
            <span id="id">
              <Translate contentKey="contractTooolApp.contractPosition.id">Id</Translate>
            </span>
            <UncontrolledTooltip target="id">
              <Translate contentKey="contractTooolApp.contractPosition.help.id" />
            </UncontrolledTooltip>
          </dt>
          <dd>{contractPositionEntity.id}</dd>
          <dt>
            <span id="contractPositionId">
              <Translate contentKey="contractTooolApp.contractPosition.contractPositionId">Contract Position Id</Translate>
            </span>
            <UncontrolledTooltip target="contractPositionId">
              <Translate contentKey="contractTooolApp.contractPosition.help.contractPositionId" />
            </UncontrolledTooltip>
          </dt>
          <dd>{contractPositionEntity.contractPositionId}</dd>
          <dt>
            <span id="employeeId">
              <Translate contentKey="contractTooolApp.contractPosition.employeeId">Employee Id</Translate>
            </span>
            <UncontrolledTooltip target="employeeId">
              <Translate contentKey="contractTooolApp.contractPosition.help.employeeId" />
            </UncontrolledTooltip>
          </dt>
          <dd>{contractPositionEntity.employeeId}</dd>
          <dt>
            <span id="numberContractPosition">
              <Translate contentKey="contractTooolApp.contractPosition.numberContractPosition">Number Contract Position</Translate>
            </span>
            <UncontrolledTooltip target="numberContractPosition">
              <Translate contentKey="contractTooolApp.contractPosition.help.numberContractPosition" />
            </UncontrolledTooltip>
          </dt>
          <dd>{contractPositionEntity.numberContractPosition}</dd>
          <dt>
            <span id="restrictionTypeId">
              <Translate contentKey="contractTooolApp.contractPosition.restrictionTypeId">Restriction Type Id</Translate>
            </span>
            <UncontrolledTooltip target="restrictionTypeId">
              <Translate contentKey="contractTooolApp.contractPosition.help.restrictionTypeId" />
            </UncontrolledTooltip>
          </dt>
          <dd>{contractPositionEntity.restrictionTypeId}</dd>
          <dt>
            <span id="restriction">
              <Translate contentKey="contractTooolApp.contractPosition.restriction">Restriction</Translate>
            </span>
            <UncontrolledTooltip target="restriction">
              <Translate contentKey="contractTooolApp.contractPosition.help.restriction" />
            </UncontrolledTooltip>
          </dt>
          <dd>{contractPositionEntity.restriction}</dd>
          <dt>
            <span id="currencyId">
              <Translate contentKey="contractTooolApp.contractPosition.currencyId">Currency Id</Translate>
            </span>
            <UncontrolledTooltip target="currencyId">
              <Translate contentKey="contractTooolApp.contractPosition.help.currencyId" />
            </UncontrolledTooltip>
          </dt>
          <dd>{contractPositionEntity.currencyId}</dd>
          <dt>
            <span id="rateAnHour">
              <Translate contentKey="contractTooolApp.contractPosition.rateAnHour">Rate An Hour</Translate>
            </span>
            <UncontrolledTooltip target="rateAnHour">
              <Translate contentKey="contractTooolApp.contractPosition.help.rateAnHour" />
            </UncontrolledTooltip>
          </dt>
          <dd>{contractPositionEntity.rateAnHour}</dd>
          <dt>
            <span id="statusId">
              <Translate contentKey="contractTooolApp.contractPosition.statusId">Status Id</Translate>
            </span>
            <UncontrolledTooltip target="statusId">
              <Translate contentKey="contractTooolApp.contractPosition.help.statusId" />
            </UncontrolledTooltip>
          </dt>
          <dd>{contractPositionEntity.statusId}</dd>
          <dt>
            <span id="lifecycleStatus">
              <Translate contentKey="contractTooolApp.contractPosition.lifecycleStatus">Lifecycle Status</Translate>
            </span>
            <UncontrolledTooltip target="lifecycleStatus">
              <Translate contentKey="contractTooolApp.contractPosition.help.lifecycleStatus" />
            </UncontrolledTooltip>
          </dt>
          <dd>{contractPositionEntity.lifecycleStatus}</dd>
          <dt>
            <Translate contentKey="contractTooolApp.contractPosition.subcontract">Subcontract</Translate>
          </dt>
          <dd>{contractPositionEntity.subcontract ? contractPositionEntity.subcontract.id : ''}</dd>
        </dl>
        <Button tag={Link} to="/contract-position" replace color="info" data-cy="entityDetailsBackButton">
          <FontAwesomeIcon icon="arrow-left" />{' '}
          <span className="d-none d-md-inline">
            <Translate contentKey="entity.action.back">Back</Translate>
          </span>
        </Button>
        &nbsp;
        <Button tag={Link} to={`/contract-position/${contractPositionEntity.id}/edit`} replace color="primary">
          <FontAwesomeIcon icon="pencil-alt" />{' '}
          <span className="d-none d-md-inline">
            <Translate contentKey="entity.action.edit">Edit</Translate>
          </span>
        </Button>
      </Col>
    </Row>
  );
};

export default ContractPositionDetail;
