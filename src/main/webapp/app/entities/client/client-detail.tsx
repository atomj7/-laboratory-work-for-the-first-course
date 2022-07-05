import React, { useEffect } from 'react';
import { Link, RouteComponentProps } from 'react-router-dom';
import { Button, UncontrolledTooltip, Row, Col } from 'reactstrap';
import { Translate } from 'react-jhipster';
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome';

import { APP_DATE_FORMAT, APP_LOCAL_DATE_FORMAT } from 'app/config/constants';
import { useAppDispatch, useAppSelector } from 'app/config/store';

import { getEntity } from './client.reducer';

export const ClientDetail = (props: RouteComponentProps<{ id: string }>) => {
  const dispatch = useAppDispatch();

  useEffect(() => {
    dispatch(getEntity(props.match.params.id));
  }, []);

  const clientEntity = useAppSelector(state => state.client.entity);
  return (
    <Row>
      <Col md="8">
        <h2 data-cy="clientDetailsHeading">
          <Translate contentKey="contractTooolApp.client.detail.title">Client</Translate>
        </h2>
        <dl className="jh-entity-details">
          <dt>
            <span id="id">
              <Translate contentKey="contractTooolApp.client.id">Id</Translate>
            </span>
          </dt>
          <dd>{clientEntity.id}</dd>
          <dt>
            <span id="name">
              <Translate contentKey="contractTooolApp.client.name">Name</Translate>
            </span>
            <UncontrolledTooltip target="name">
              <Translate contentKey="contractTooolApp.client.help.name" />
            </UncontrolledTooltip>
          </dt>
          <dd>{clientEntity.name}</dd>
          <dt>
            <span id="salesManagerId">
              <Translate contentKey="contractTooolApp.client.salesManagerId">Sales Manager Id</Translate>
            </span>
            <UncontrolledTooltip target="salesManagerId">
              <Translate contentKey="contractTooolApp.client.help.salesManagerId" />
            </UncontrolledTooltip>
          </dt>
          <dd>{clientEntity.salesManagerId}</dd>
          <dt>
            <span id="countryId">
              <Translate contentKey="contractTooolApp.client.countryId">Country Id</Translate>
            </span>
            <UncontrolledTooltip target="countryId">
              <Translate contentKey="contractTooolApp.client.help.countryId" />
            </UncontrolledTooltip>
          </dt>
          <dd>{clientEntity.countryId}</dd>
          <dt>
            <span id="partnerStatus">
              <Translate contentKey="contractTooolApp.client.partnerStatus">Partner Status</Translate>
            </span>
            <UncontrolledTooltip target="partnerStatus">
              <Translate contentKey="contractTooolApp.client.help.partnerStatus" />
            </UncontrolledTooltip>
          </dt>
          <dd>{clientEntity.partnerStatus ? 'true' : 'false'}</dd>
          <dt>
            <span id="contactPerson">
              <Translate contentKey="contractTooolApp.client.contactPerson">Contact Person</Translate>
            </span>
            <UncontrolledTooltip target="contactPerson">
              <Translate contentKey="contractTooolApp.client.help.contactPerson" />
            </UncontrolledTooltip>
          </dt>
          <dd>{clientEntity.contactPerson}</dd>
          <dt>
            <span id="contractEmail">
              <Translate contentKey="contractTooolApp.client.contractEmail">Contract Email</Translate>
            </span>
            <UncontrolledTooltip target="contractEmail">
              <Translate contentKey="contractTooolApp.client.help.contractEmail" />
            </UncontrolledTooltip>
          </dt>
          <dd>{clientEntity.contractEmail}</dd>
          <dt>
            <span id="industryId">
              <Translate contentKey="contractTooolApp.client.industryId">Industry Id</Translate>
            </span>
            <UncontrolledTooltip target="industryId">
              <Translate contentKey="contractTooolApp.client.help.industryId" />
            </UncontrolledTooltip>
          </dt>
          <dd>{clientEntity.industryId}</dd>
          <dt>
            <span id="signer">
              <Translate contentKey="contractTooolApp.client.signer">Signer</Translate>
            </span>
            <UncontrolledTooltip target="signer">
              <Translate contentKey="contractTooolApp.client.help.signer" />
            </UncontrolledTooltip>
          </dt>
          <dd>{clientEntity.signer}</dd>
          <dt>
            <span id="signerPosition">
              <Translate contentKey="contractTooolApp.client.signerPosition">Signer Position</Translate>
            </span>
            <UncontrolledTooltip target="signerPosition">
              <Translate contentKey="contractTooolApp.client.help.signerPosition" />
            </UncontrolledTooltip>
          </dt>
          <dd>{clientEntity.signerPosition}</dd>
          <dt>
            <span id="legalAddress">
              <Translate contentKey="contractTooolApp.client.legalAddress">Legal Address</Translate>
            </span>
            <UncontrolledTooltip target="legalAddress">
              <Translate contentKey="contractTooolApp.client.help.legalAddress" />
            </UncontrolledTooltip>
          </dt>
          <dd>{clientEntity.legalAddress}</dd>
          <dt>
            <span id="registrationNumber">
              <Translate contentKey="contractTooolApp.client.registrationNumber">Registration Number</Translate>
            </span>
            <UncontrolledTooltip target="registrationNumber">
              <Translate contentKey="contractTooolApp.client.help.registrationNumber" />
            </UncontrolledTooltip>
          </dt>
          <dd>{clientEntity.registrationNumber}</dd>
          <dt>
            <span id="baseOfActivityId">
              <Translate contentKey="contractTooolApp.client.baseOfActivityId">Base Of Activity Id</Translate>
            </span>
            <UncontrolledTooltip target="baseOfActivityId">
              <Translate contentKey="contractTooolApp.client.help.baseOfActivityId" />
            </UncontrolledTooltip>
          </dt>
          <dd>{clientEntity.baseOfActivityId}</dd>
          <dt>
            <span id="vatNumber">
              <Translate contentKey="contractTooolApp.client.vatNumber">Vat Number</Translate>
            </span>
            <UncontrolledTooltip target="vatNumber">
              <Translate contentKey="contractTooolApp.client.help.vatNumber" />
            </UncontrolledTooltip>
          </dt>
          <dd>{clientEntity.vatNumber}</dd>
          <dt>
            <span id="bankName">
              <Translate contentKey="contractTooolApp.client.bankName">Bank Name</Translate>
            </span>
            <UncontrolledTooltip target="bankName">
              <Translate contentKey="contractTooolApp.client.help.bankName" />
            </UncontrolledTooltip>
          </dt>
          <dd>{clientEntity.bankName}</dd>
          <dt>
            <span id="bankAddress">
              <Translate contentKey="contractTooolApp.client.bankAddress">Bank Address</Translate>
            </span>
            <UncontrolledTooltip target="bankAddress">
              <Translate contentKey="contractTooolApp.client.help.bankAddress" />
            </UncontrolledTooltip>
          </dt>
          <dd>{clientEntity.bankAddress}</dd>
          <dt>
            <span id="swiftCode">
              <Translate contentKey="contractTooolApp.client.swiftCode">Swift Code</Translate>
            </span>
            <UncontrolledTooltip target="swiftCode">
              <Translate contentKey="contractTooolApp.client.help.swiftCode" />
            </UncontrolledTooltip>
          </dt>
          <dd>{clientEntity.swiftCode}</dd>
          <dt>
            <span id="ibanCode">
              <Translate contentKey="contractTooolApp.client.ibanCode">Iban Code</Translate>
            </span>
            <UncontrolledTooltip target="ibanCode">
              <Translate contentKey="contractTooolApp.client.help.ibanCode" />
            </UncontrolledTooltip>
          </dt>
          <dd>{clientEntity.ibanCode}</dd>
          <dt>
            <span id="lifecycleStatus">
              <Translate contentKey="contractTooolApp.client.lifecycleStatus">Lifecycle Status</Translate>
            </span>
            <UncontrolledTooltip target="lifecycleStatus">
              <Translate contentKey="contractTooolApp.client.help.lifecycleStatus" />
            </UncontrolledTooltip>
          </dt>
          <dd>{clientEntity.lifecycleStatus}</dd>
        </dl>
        <Button tag={Link} to="/client" replace color="info" data-cy="entityDetailsBackButton">
          <FontAwesomeIcon icon="arrow-left" />{' '}
          <span className="d-none d-md-inline">
            <Translate contentKey="entity.action.back">Back</Translate>
          </span>
        </Button>
        &nbsp;
        <Button tag={Link} to={`/client/${clientEntity.id}/edit`} replace color="primary">
          <FontAwesomeIcon icon="pencil-alt" />{' '}
          <span className="d-none d-md-inline">
            <Translate contentKey="entity.action.edit">Edit</Translate>
          </span>
        </Button>
      </Col>
    </Row>
  );
};

export default ClientDetail;
