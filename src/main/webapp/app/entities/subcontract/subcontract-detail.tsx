import React, { useEffect } from 'react';
import { Link, RouteComponentProps } from 'react-router-dom';
import { Button, UncontrolledTooltip, Row, Col } from 'reactstrap';
import { Translate, TextFormat } from 'react-jhipster';
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome';

import { APP_DATE_FORMAT, APP_LOCAL_DATE_FORMAT } from 'app/config/constants';
import { useAppDispatch, useAppSelector } from 'app/config/store';

import { getEntity } from './subcontract.reducer';

export const SubcontractDetail = (props: RouteComponentProps<{ id: string }>) => {
  const dispatch = useAppDispatch();

  useEffect(() => {
    dispatch(getEntity(props.match.params.id));
  }, []);

  const subcontractEntity = useAppSelector(state => state.subcontract.entity);
  return (
    <Row>
      <Col md="8">
        <h2 data-cy="subcontractDetailsHeading">
          <Translate contentKey="contractTooolApp.subcontract.detail.title">Subcontract</Translate>
        </h2>
        <dl className="jh-entity-details">
          <dt>
            <span id="id">
              <Translate contentKey="contractTooolApp.subcontract.id">Id</Translate>
            </span>
            <UncontrolledTooltip target="id">
              <Translate contentKey="contractTooolApp.subcontract.help.id" />
            </UncontrolledTooltip>
          </dt>
          <dd>{subcontractEntity.id}</dd>
          <dt>
            <span id="subcontractCipher">
              <Translate contentKey="contractTooolApp.subcontract.subcontractCipher">Subcontract Cipher</Translate>
            </span>
            <UncontrolledTooltip target="subcontractCipher">
              <Translate contentKey="contractTooolApp.subcontract.help.subcontractCipher" />
            </UncontrolledTooltip>
          </dt>
          <dd>{subcontractEntity.subcontractCipher}</dd>
          <dt>
            <span id="statusId">
              <Translate contentKey="contractTooolApp.subcontract.statusId">Status Id</Translate>
            </span>
            <UncontrolledTooltip target="statusId">
              <Translate contentKey="contractTooolApp.subcontract.help.statusId" />
            </UncontrolledTooltip>
          </dt>
          <dd>{subcontractEntity.statusId}</dd>
          <dt>
            <span id="cooperationTypeId">
              <Translate contentKey="contractTooolApp.subcontract.cooperationTypeId">Cooperation Type Id</Translate>
            </span>
            <UncontrolledTooltip target="cooperationTypeId">
              <Translate contentKey="contractTooolApp.subcontract.help.cooperationTypeId" />
            </UncontrolledTooltip>
          </dt>
          <dd>{subcontractEntity.cooperationTypeId}</dd>
          <dt>
            <span id="sum">
              <Translate contentKey="contractTooolApp.subcontract.sum">Sum</Translate>
            </span>
            <UncontrolledTooltip target="sum">
              <Translate contentKey="contractTooolApp.subcontract.help.sum" />
            </UncontrolledTooltip>
          </dt>
          <dd>{subcontractEntity.sum}</dd>
          <dt>
            <span id="positions">
              <Translate contentKey="contractTooolApp.subcontract.positions">Positions</Translate>
            </span>
            <UncontrolledTooltip target="positions">
              <Translate contentKey="contractTooolApp.subcontract.help.positions" />
            </UncontrolledTooltip>
          </dt>
          <dd>{subcontractEntity.positions}</dd>
          <dt>
            <span id="currencyId">
              <Translate contentKey="contractTooolApp.subcontract.currencyId">Currency Id</Translate>
            </span>
            <UncontrolledTooltip target="currencyId">
              <Translate contentKey="contractTooolApp.subcontract.help.currencyId" />
            </UncontrolledTooltip>
          </dt>
          <dd>{subcontractEntity.currencyId}</dd>
          <dt>
            <span id="paymentTermTypeId">
              <Translate contentKey="contractTooolApp.subcontract.paymentTermTypeId">Payment Term Type Id</Translate>
            </span>
            <UncontrolledTooltip target="paymentTermTypeId">
              <Translate contentKey="contractTooolApp.subcontract.help.paymentTermTypeId" />
            </UncontrolledTooltip>
          </dt>
          <dd>{subcontractEntity.paymentTermTypeId}</dd>
          <dt>
            <span id="paymentTermId">
              <Translate contentKey="contractTooolApp.subcontract.paymentTermId">Payment Term Id</Translate>
            </span>
            <UncontrolledTooltip target="paymentTermId">
              <Translate contentKey="contractTooolApp.subcontract.help.paymentTermId" />
            </UncontrolledTooltip>
          </dt>
          <dd>{subcontractEntity.paymentTermId}</dd>
          <dt>
            <span id="startDate">
              <Translate contentKey="contractTooolApp.subcontract.startDate">Start Date</Translate>
            </span>
            <UncontrolledTooltip target="startDate">
              <Translate contentKey="contractTooolApp.subcontract.help.startDate" />
            </UncontrolledTooltip>
          </dt>
          <dd>
            {subcontractEntity.startDate ? (
              <TextFormat value={subcontractEntity.startDate} type="date" format={APP_LOCAL_DATE_FORMAT} />
            ) : null}
          </dd>
          <dt>
            <span id="finishDate">
              <Translate contentKey="contractTooolApp.subcontract.finishDate">Finish Date</Translate>
            </span>
            <UncontrolledTooltip target="finishDate">
              <Translate contentKey="contractTooolApp.subcontract.help.finishDate" />
            </UncontrolledTooltip>
          </dt>
          <dd>
            {subcontractEntity.finishDate ? (
              <TextFormat value={subcontractEntity.finishDate} type="date" format={APP_LOCAL_DATE_FORMAT} />
            ) : null}
          </dd>
          <dt>
            <span id="typeId">
              <Translate contentKey="contractTooolApp.subcontract.typeId">Type Id</Translate>
            </span>
            <UncontrolledTooltip target="typeId">
              <Translate contentKey="contractTooolApp.subcontract.help.typeId" />
            </UncontrolledTooltip>
          </dt>
          <dd>{subcontractEntity.typeId}</dd>
          <dt>
            <span id="tasktTypeId">
              <Translate contentKey="contractTooolApp.subcontract.tasktTypeId">Taskt Type Id</Translate>
            </span>
            <UncontrolledTooltip target="tasktTypeId">
              <Translate contentKey="contractTooolApp.subcontract.help.tasktTypeId" />
            </UncontrolledTooltip>
          </dt>
          <dd>{subcontractEntity.tasktTypeId}</dd>
          <dt>
            <span id="technologyId">
              <Translate contentKey="contractTooolApp.subcontract.technologyId">Technology Id</Translate>
            </span>
            <UncontrolledTooltip target="technologyId">
              <Translate contentKey="contractTooolApp.subcontract.help.technologyId" />
            </UncontrolledTooltip>
          </dt>
          <dd>{subcontractEntity.technologyId}</dd>
          <dt>
            <span id="domainId">
              <Translate contentKey="contractTooolApp.subcontract.domainId">Domain Id</Translate>
            </span>
            <UncontrolledTooltip target="domainId">
              <Translate contentKey="contractTooolApp.subcontract.help.domainId" />
            </UncontrolledTooltip>
          </dt>
          <dd>{subcontractEntity.domainId}</dd>
          <dt>
            <span id="link">
              <Translate contentKey="contractTooolApp.subcontract.link">Link</Translate>
            </span>
            <UncontrolledTooltip target="link">
              <Translate contentKey="contractTooolApp.subcontract.help.link" />
            </UncontrolledTooltip>
          </dt>
          <dd>{subcontractEntity.link}</dd>
          <dt>
            <span id="lifecycleStatus">
              <Translate contentKey="contractTooolApp.subcontract.lifecycleStatus">Lifecycle Status</Translate>
            </span>
            <UncontrolledTooltip target="lifecycleStatus">
              <Translate contentKey="contractTooolApp.subcontract.help.lifecycleStatus" />
            </UncontrolledTooltip>
          </dt>
          <dd>{subcontractEntity.lifecycleStatus}</dd>
          <dt>
            <Translate contentKey="contractTooolApp.subcontract.contract">Contract</Translate>
          </dt>
          <dd>{subcontractEntity.contract ? subcontractEntity.contract.id : ''}</dd>
          <dt>
            <Translate contentKey="contractTooolApp.subcontract.project">Project</Translate>
          </dt>
          <dd>{subcontractEntity.project ? subcontractEntity.project.id : ''}</dd>
        </dl>
        <Button tag={Link} to="/subcontract" replace color="info" data-cy="entityDetailsBackButton">
          <FontAwesomeIcon icon="arrow-left" />{' '}
          <span className="d-none d-md-inline">
            <Translate contentKey="entity.action.back">Back</Translate>
          </span>
        </Button>
        &nbsp;
        <Button tag={Link} to={`/subcontract/${subcontractEntity.id}/edit`} replace color="primary">
          <FontAwesomeIcon icon="pencil-alt" />{' '}
          <span className="d-none d-md-inline">
            <Translate contentKey="entity.action.edit">Edit</Translate>
          </span>
        </Button>
      </Col>
    </Row>
  );
};

export default SubcontractDetail;
