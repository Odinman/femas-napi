#include "Trader.h"

void Trader::AsyncFn(uv_work_t *req){};

void Trader::AsyncAfterFn(uv_work_t *req) {
  if (Trader::isDebug) {
    std::cout << "[DEBUG in C++]: "
              << "AsyncAfterFn called." << std::endl;
  }
  TdCbField *field = (TdCbField *)req->data;
  int eventId      = field->eventId;
  Napi::Env env    = field->trader->Env();
  Napi::HandleScope scope(env);
  Napi::Object obj = Napi::Object::New(env);

  if (eventId == ON_FRONT_CONNECTED) {
  } else if (eventId == ON_QRY_FRONT_CONNECTED) {
  } else if (eventId == ON_FRONT_DISCONNECTED) {
    SET_PROPERTY_NUMBER(env, obj, "ErrorCode", field->errCode);
  } else if (eventId == ON_QRY_FRONT_DISCONNECTED) {
    SET_PROPERTY_NUMBER(env, obj, "ErrorCode", field->errCode);
  } else if (eventId == ON_HEART_BEAT_WARNING) {
    SET_PROPERTY_NUMBER(env, obj, "ErrorCode", field->errCode);
  } else if (eventId == ON_PACKAGE_START) {
    SET_PROPERTY_NUMBER(env, obj, "nSequenceNo", field->errCode);
  } else if (eventId == ON_PACKAGE_END) {
    SET_PROPERTY_NUMBER(env, obj, "nSequenceNo", field->errCode);
  } else if (eventId == ON_RSP_ERROR) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_USER_LOGIN) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcRspUserLoginField *info = static_cast<CUstpFtdcRspUserLoginField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_STRING(env, obj, "LoginTime", info->LoginTime);
      SET_PROPERTY_STRING(env, obj, "ExchangeTime", info->ExchangeTime);
      SET_PROPERTY_STRING(env, obj, "MaxOrderLocalID", info->MaxOrderLocalID);
      SET_PROPERTY_BUFFER(env, obj, "TradingSystemName", info->TradingSystemName);
      SET_PROPERTY_NUMBER(env, obj, "DataCenterID", info->DataCenterID);
      SET_PROPERTY_NUMBER(env, obj, "PrivateFlowSize", info->PrivateFlowSize);
      SET_PROPERTY_NUMBER(env, obj, "UserFlowSize", info->UserFlowSize);
      SET_PROPERTY_STRING(env, obj, "ActionDay", info->ActionDay);
      SET_PROPERTY_STRING(env, obj, "FemasVersion", info->FemasVersion);
      SET_PROPERTY_NUMBER(env, obj, "FemasLifeCycle", info->FemasLifeCycle);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_USER_LOGOUT) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcRspUserLogoutField *info = static_cast<CUstpFtdcRspUserLogoutField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_USER_PASSWORD_UPDATE) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcUserPasswordUpdateField *info = static_cast<CUstpFtdcUserPasswordUpdateField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_STRING(env, obj, "OldPassword", info->OldPassword);
      SET_PROPERTY_STRING(env, obj, "NewPassword", info->NewPassword);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_SETTLEMENT_INFO_CONFIRM) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcInputSettlementInfoConfirmField *info = static_cast<CUstpFtdcInputSettlementInfoConfirmField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_STRING(env, obj, "ConfirmDate", info->ConfirmDate);
      SET_PROPERTY_STRING(env, obj, "ConfirmTime", info->ConfirmTime);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_QRY_SETTLEMENT_INFO_CONFIRM) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcSettlementInfoConfirmField *info = static_cast<CUstpFtdcSettlementInfoConfirmField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_STRING(env, obj, "ConfirmDate", info->ConfirmDate);
      SET_PROPERTY_STRING(env, obj, "ConfirmTime", info->ConfirmTime);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_ORDER_INSERT) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcInputOrderField *info = static_cast<CUstpFtdcInputOrderField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "OrderSysID", info->OrderSysID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_NUMBER(env, obj, "SeatNo", info->SeatNo);
      SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
      SET_PROPERTY_STRING(env, obj, "UserOrderLocalID", info->UserOrderLocalID);
      SET_PROPERTY_NUMBER(env, obj, "LimitPrice", info->LimitPrice);
      SET_PROPERTY_NUMBER(env, obj, "Volume", info->Volume);
      SET_PROPERTY_STRING(env, obj, "GTDDate", info->GTDDate);
      SET_PROPERTY_NUMBER(env, obj, "MinVolume", info->MinVolume);
      SET_PROPERTY_NUMBER(env, obj, "StopPrice", info->StopPrice);
      SET_PROPERTY_NUMBER(env, obj, "IsAutoSuspend", info->IsAutoSuspend);
      SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
      SET_PROPERTY_STRING(env, obj, "UserCustom", info->UserCustom);
      SET_PROPERTY_NUMBER(env, obj, "BusinessLocalID", info->BusinessLocalID);
      SET_PROPERTY_STRING(env, obj, "ActionDay", info->ActionDay);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_ORDER_ACTION) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcOrderActionField *info = static_cast<CUstpFtdcOrderActionField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "OrderSysID", info->OrderSysID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_STRING(env, obj, "UserOrderActionLocalID", info->UserOrderActionLocalID);
      SET_PROPERTY_STRING(env, obj, "UserOrderLocalID", info->UserOrderLocalID);
      SET_PROPERTY_NUMBER(env, obj, "LimitPrice", info->LimitPrice);
      SET_PROPERTY_NUMBER(env, obj, "VolumeChange", info->VolumeChange);
      SET_PROPERTY_NUMBER(env, obj, "BusinessLocalID", info->BusinessLocalID);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_QUOTE_INSERT) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcInputQuoteField *info = static_cast<CUstpFtdcInputQuoteField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
      SET_PROPERTY_STRING(env, obj, "QuoteSysID", info->QuoteSysID);
      SET_PROPERTY_STRING(env, obj, "UserQuoteLocalID", info->UserQuoteLocalID);
      SET_PROPERTY_STRING(env, obj, "QuoteLocalID", info->QuoteLocalID);
      SET_PROPERTY_NUMBER(env, obj, "BidVolume", info->BidVolume);
      SET_PROPERTY_NUMBER(env, obj, "BidPrice", info->BidPrice);
      SET_PROPERTY_NUMBER(env, obj, "AskVolume", info->AskVolume);
      SET_PROPERTY_NUMBER(env, obj, "AskPrice", info->AskPrice);
      SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
      SET_PROPERTY_STRING(env, obj, "UserCustom", info->UserCustom);
      SET_PROPERTY_STRING(env, obj, "BidUserOrderLocalID", info->BidUserOrderLocalID);
      SET_PROPERTY_STRING(env, obj, "AskUserOrderLocalID", info->AskUserOrderLocalID);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_QUOTE_ACTION) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcQuoteActionField *info = static_cast<CUstpFtdcQuoteActionField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_STRING(env, obj, "QuoteSysID", info->QuoteSysID);
      SET_PROPERTY_STRING(env, obj, "UserQuoteLocalID", info->UserQuoteLocalID);
      SET_PROPERTY_STRING(env, obj, "UserQuoteActionLocalID", info->UserQuoteActionLocalID);
      SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
      SET_PROPERTY_STRING(env, obj, "UserCustom", info->UserCustom);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_FOR_QUOTE) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcReqForQuoteField *info = static_cast<CUstpFtdcReqForQuoteField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "ReqForQuoteID", info->ReqForQuoteID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_STRING(env, obj, "ReqForQuoteTime", info->ReqForQuoteTime);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_MARGIN_COMB_ACTION) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcInputMarginCombActionField *info = static_cast<CUstpFtdcInputMarginCombActionField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_STRING(env, obj, "UserActionLocalID", info->UserActionLocalID);
      SET_PROPERTY_STRING(env, obj, "CombInstrumentID", info->CombInstrumentID);
      SET_PROPERTY_NUMBER(env, obj, "CombVolume", info->CombVolume);
      SET_PROPERTY_STRING(env, obj, "ActionLocalID", info->ActionLocalID);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_USER_DEPOSIT) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcstpUserDepositField *info = static_cast<CUstpFtdcstpUserDepositField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_NUMBER(env, obj, "Amount", info->Amount);
      SET_PROPERTY_STRING(env, obj, "UserOrderLocalID", info->UserOrderLocalID);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_TRANSFER_MONEY) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcstpTransferMoneyField *info = static_cast<CUstpFtdcstpTransferMoneyField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_NUMBER(env, obj, "Amount", info->Amount);
      SET_PROPERTY_STRING(env, obj, "UserOrderLocalID", info->UserOrderLocalID);
      SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
      SET_PROPERTY_STRING(env, obj, "BankPasswd", info->BankPasswd);
      SET_PROPERTY_STRING(env, obj, "AccountPasswd", info->AccountPasswd);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RTN_FLOW_MESSAGE_CANCEL) {
    if (!!field->data) {
      CUstpFtdcFlowMessageCancelField *info = static_cast<CUstpFtdcFlowMessageCancelField *>(field->data);
      SET_PROPERTY_NUMBER(env, obj, "SequenceSeries", info->SequenceSeries);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_NUMBER(env, obj, "DataCenterID", info->DataCenterID);
      SET_PROPERTY_NUMBER(env, obj, "StartSequenceNo", info->StartSequenceNo);
      SET_PROPERTY_NUMBER(env, obj, "EndSequenceNo", info->EndSequenceNo);
    };
  } else if (eventId == ON_RTN_TRADE) {
    if (!!field->data) {
      CUstpFtdcTradeField *info = static_cast<CUstpFtdcTradeField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_STRING(env, obj, "ParticipantID", info->ParticipantID);
      SET_PROPERTY_STRING(env, obj, "SeatID", info->SeatID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_STRING(env, obj, "OrderUserID", info->OrderUserID);
      SET_PROPERTY_STRING(env, obj, "TradeID", info->TradeID);
      SET_PROPERTY_STRING(env, obj, "OrderSysID", info->OrderSysID);
      SET_PROPERTY_STRING(env, obj, "UserOrderLocalID", info->UserOrderLocalID);
      SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
      SET_PROPERTY_NUMBER(env, obj, "TradePrice", info->TradePrice);
      SET_PROPERTY_NUMBER(env, obj, "TradeVolume", info->TradeVolume);
      SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
      SET_PROPERTY_STRING(env, obj, "ClearingPartID", info->ClearingPartID);
      SET_PROPERTY_NUMBER(env, obj, "UsedFee", info->UsedFee);
      SET_PROPERTY_NUMBER(env, obj, "UsedMargin", info->UsedMargin);
      SET_PROPERTY_NUMBER(env, obj, "Premium", info->Premium);
      SET_PROPERTY_NUMBER(env, obj, "Position", info->Position);
      SET_PROPERTY_NUMBER(env, obj, "PositionCost", info->PositionCost);
      SET_PROPERTY_NUMBER(env, obj, "Available", info->Available);
      SET_PROPERTY_NUMBER(env, obj, "Margin", info->Margin);
      SET_PROPERTY_NUMBER(env, obj, "FrozenMargin", info->FrozenMargin);
      SET_PROPERTY_NUMBER(env, obj, "BusinessLocalID", info->BusinessLocalID);
      SET_PROPERTY_STRING(env, obj, "ActionDay", info->ActionDay);
      SET_PROPERTY_STRING(env, obj, "ArbiInstrumentID", info->ArbiInstrumentID);
    };
  } else if (eventId == ON_RTN_ORDER) {
    if (!!field->data) {
      CUstpFtdcOrderField *info = static_cast<CUstpFtdcOrderField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "OrderSysID", info->OrderSysID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_NUMBER(env, obj, "SeatNo", info->SeatNo);
      SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
      SET_PROPERTY_STRING(env, obj, "UserOrderLocalID", info->UserOrderLocalID);
      SET_PROPERTY_NUMBER(env, obj, "LimitPrice", info->LimitPrice);
      SET_PROPERTY_NUMBER(env, obj, "Volume", info->Volume);
      SET_PROPERTY_STRING(env, obj, "GTDDate", info->GTDDate);
      SET_PROPERTY_NUMBER(env, obj, "MinVolume", info->MinVolume);
      SET_PROPERTY_NUMBER(env, obj, "StopPrice", info->StopPrice);
      SET_PROPERTY_NUMBER(env, obj, "IsAutoSuspend", info->IsAutoSuspend);
      SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
      SET_PROPERTY_STRING(env, obj, "UserCustom", info->UserCustom);
      SET_PROPERTY_NUMBER(env, obj, "BusinessLocalID", info->BusinessLocalID);
      SET_PROPERTY_STRING(env, obj, "ActionDay", info->ActionDay);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_STRING(env, obj, "ParticipantID", info->ParticipantID);
      SET_PROPERTY_STRING(env, obj, "OrderUserID", info->OrderUserID);
      SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
      SET_PROPERTY_STRING(env, obj, "SeatID", info->SeatID);
      SET_PROPERTY_STRING(env, obj, "InsertTime", info->InsertTime);
      SET_PROPERTY_STRING(env, obj, "OrderLocalID", info->OrderLocalID);
      SET_PROPERTY_STRING(env, obj, "CancelTime", info->CancelTime);
      SET_PROPERTY_STRING(env, obj, "CancelUserID", info->CancelUserID);
      SET_PROPERTY_NUMBER(env, obj, "VolumeTraded", info->VolumeTraded);
      SET_PROPERTY_NUMBER(env, obj, "VolumeRemain", info->VolumeRemain);
    };
  } else if (eventId == ON_ERR_RTN_ORDER_INSERT) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcInputOrderField *info = static_cast<CUstpFtdcInputOrderField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "OrderSysID", info->OrderSysID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_NUMBER(env, obj, "SeatNo", info->SeatNo);
      SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
      SET_PROPERTY_STRING(env, obj, "UserOrderLocalID", info->UserOrderLocalID);
      SET_PROPERTY_NUMBER(env, obj, "LimitPrice", info->LimitPrice);
      SET_PROPERTY_NUMBER(env, obj, "Volume", info->Volume);
      SET_PROPERTY_STRING(env, obj, "GTDDate", info->GTDDate);
      SET_PROPERTY_NUMBER(env, obj, "MinVolume", info->MinVolume);
      SET_PROPERTY_NUMBER(env, obj, "StopPrice", info->StopPrice);
      SET_PROPERTY_NUMBER(env, obj, "IsAutoSuspend", info->IsAutoSuspend);
      SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
      SET_PROPERTY_STRING(env, obj, "UserCustom", info->UserCustom);
      SET_PROPERTY_NUMBER(env, obj, "BusinessLocalID", info->BusinessLocalID);
      SET_PROPERTY_STRING(env, obj, "ActionDay", info->ActionDay);
    };
  } else if (eventId == ON_ERR_RTN_ORDER_ACTION) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcOrderActionField *info = static_cast<CUstpFtdcOrderActionField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "OrderSysID", info->OrderSysID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_STRING(env, obj, "UserOrderActionLocalID", info->UserOrderActionLocalID);
      SET_PROPERTY_STRING(env, obj, "UserOrderLocalID", info->UserOrderLocalID);
      SET_PROPERTY_NUMBER(env, obj, "LimitPrice", info->LimitPrice);
      SET_PROPERTY_NUMBER(env, obj, "VolumeChange", info->VolumeChange);
      SET_PROPERTY_NUMBER(env, obj, "BusinessLocalID", info->BusinessLocalID);
    };
  } else if (eventId == ON_RTN_INSTRUMENT_STATUS) {
    if (!!field->data) {
      CUstpFtdcInstrumentStatusField *info = static_cast<CUstpFtdcInstrumentStatusField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "ProductID", info->ProductID);
      SET_PROPERTY_BUFFER(env, obj, "ProductName", info->ProductName);
      SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
      SET_PROPERTY_BUFFER(env, obj, "InstrumentName", info->InstrumentName);
      SET_PROPERTY_NUMBER(env, obj, "DeliveryYear", info->DeliveryYear);
      SET_PROPERTY_NUMBER(env, obj, "DeliveryMonth", info->DeliveryMonth);
      SET_PROPERTY_NUMBER(env, obj, "MaxLimitOrderVolume", info->MaxLimitOrderVolume);
      SET_PROPERTY_NUMBER(env, obj, "MinLimitOrderVolume", info->MinLimitOrderVolume);
      SET_PROPERTY_NUMBER(env, obj, "MaxMarketOrderVolume", info->MaxMarketOrderVolume);
      SET_PROPERTY_NUMBER(env, obj, "MinMarketOrderVolume", info->MinMarketOrderVolume);
      SET_PROPERTY_NUMBER(env, obj, "VolumeMultiple", info->VolumeMultiple);
      SET_PROPERTY_NUMBER(env, obj, "PriceTick", info->PriceTick);
      SET_PROPERTY_NUMBER(env, obj, "LongPosLimit", info->LongPosLimit);
      SET_PROPERTY_NUMBER(env, obj, "ShortPosLimit", info->ShortPosLimit);
      SET_PROPERTY_NUMBER(env, obj, "LowerLimitPrice", info->LowerLimitPrice);
      SET_PROPERTY_NUMBER(env, obj, "UpperLimitPrice", info->UpperLimitPrice);
      SET_PROPERTY_NUMBER(env, obj, "PreSettlementPrice", info->PreSettlementPrice);
      SET_PROPERTY_STRING(env, obj, "CreateDate", info->CreateDate);
      SET_PROPERTY_STRING(env, obj, "OpenDate", info->OpenDate);
      SET_PROPERTY_STRING(env, obj, "ExpireDate", info->ExpireDate);
      SET_PROPERTY_STRING(env, obj, "StartDelivDate", info->StartDelivDate);
      SET_PROPERTY_STRING(env, obj, "EndDelivDate", info->EndDelivDate);
      SET_PROPERTY_NUMBER(env, obj, "BasisPrice", info->BasisPrice);
      SET_PROPERTY_NUMBER(env, obj, "IsTrading", info->IsTrading);
      SET_PROPERTY_STRING(env, obj, "UnderlyingInstrID", info->UnderlyingInstrID);
      SET_PROPERTY_NUMBER(env, obj, "UnderlyingMultiple", info->UnderlyingMultiple);
      SET_PROPERTY_NUMBER(env, obj, "StrikePrice", info->StrikePrice);
      SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
      SET_PROPERTY_STRING(env, obj, "EnterDate", info->EnterDate);
    };
  } else if (eventId == ON_RTN_INVESTOR_ACCOUNT_DEPOSIT) {
    if (!!field->data) {
      CUstpFtdcInvestorAccountDepositResField *info = static_cast<CUstpFtdcInvestorAccountDepositResField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
      SET_PROPERTY_STRING(env, obj, "AccountSeqNo", info->AccountSeqNo);
      SET_PROPERTY_NUMBER(env, obj, "Amount", info->Amount);
      SET_PROPERTY_NUMBER(env, obj, "Available", info->Available);
      SET_PROPERTY_NUMBER(env, obj, "Balance", info->Balance);
    };
  } else if (eventId == ON_RTN_QUOTE) {
    if (!!field->data) {
      CUstpFtdcRtnQuoteField *info = static_cast<CUstpFtdcRtnQuoteField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
      SET_PROPERTY_STRING(env, obj, "QuoteSysID", info->QuoteSysID);
      SET_PROPERTY_STRING(env, obj, "UserQuoteLocalID", info->UserQuoteLocalID);
      SET_PROPERTY_STRING(env, obj, "QuoteLocalID", info->QuoteLocalID);
      SET_PROPERTY_NUMBER(env, obj, "BidVolume", info->BidVolume);
      SET_PROPERTY_NUMBER(env, obj, "BidPrice", info->BidPrice);
      SET_PROPERTY_NUMBER(env, obj, "AskVolume", info->AskVolume);
      SET_PROPERTY_NUMBER(env, obj, "AskPrice", info->AskPrice);
      SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
      SET_PROPERTY_STRING(env, obj, "UserCustom", info->UserCustom);
      SET_PROPERTY_STRING(env, obj, "BidUserOrderLocalID", info->BidUserOrderLocalID);
      SET_PROPERTY_STRING(env, obj, "AskUserOrderLocalID", info->AskUserOrderLocalID);
      SET_PROPERTY_STRING(env, obj, "BidOrderSysID", info->BidOrderSysID);
      SET_PROPERTY_STRING(env, obj, "AskOrderSysID", info->AskOrderSysID);
      SET_PROPERTY_STRING(env, obj, "InsertTime", info->InsertTime);
      SET_PROPERTY_STRING(env, obj, "CancelTime", info->CancelTime);
      SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
    };
  } else if (eventId == ON_ERR_RTN_QUOTE_INSERT) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcInputQuoteField *info = static_cast<CUstpFtdcInputQuoteField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
      SET_PROPERTY_STRING(env, obj, "QuoteSysID", info->QuoteSysID);
      SET_PROPERTY_STRING(env, obj, "UserQuoteLocalID", info->UserQuoteLocalID);
      SET_PROPERTY_STRING(env, obj, "QuoteLocalID", info->QuoteLocalID);
      SET_PROPERTY_NUMBER(env, obj, "BidVolume", info->BidVolume);
      SET_PROPERTY_NUMBER(env, obj, "BidPrice", info->BidPrice);
      SET_PROPERTY_NUMBER(env, obj, "AskVolume", info->AskVolume);
      SET_PROPERTY_NUMBER(env, obj, "AskPrice", info->AskPrice);
      SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
      SET_PROPERTY_STRING(env, obj, "UserCustom", info->UserCustom);
      SET_PROPERTY_STRING(env, obj, "BidUserOrderLocalID", info->BidUserOrderLocalID);
      SET_PROPERTY_STRING(env, obj, "AskUserOrderLocalID", info->AskUserOrderLocalID);
    };
  } else if (eventId == ON_ERR_RTN_QUOTE_ACTION) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcOrderActionField *info = static_cast<CUstpFtdcOrderActionField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "OrderSysID", info->OrderSysID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_STRING(env, obj, "UserOrderActionLocalID", info->UserOrderActionLocalID);
      SET_PROPERTY_STRING(env, obj, "UserOrderLocalID", info->UserOrderLocalID);
      SET_PROPERTY_NUMBER(env, obj, "LimitPrice", info->LimitPrice);
      SET_PROPERTY_NUMBER(env, obj, "VolumeChange", info->VolumeChange);
      SET_PROPERTY_NUMBER(env, obj, "BusinessLocalID", info->BusinessLocalID);
    };
  } else if (eventId == ON_RTN_FOR_QUOTE) {
    if (!!field->data) {
      CUstpFtdcReqForQuoteField *info = static_cast<CUstpFtdcReqForQuoteField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "ReqForQuoteID", info->ReqForQuoteID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_STRING(env, obj, "ReqForQuoteTime", info->ReqForQuoteTime);
    };
  } else if (eventId == ON_RTN_MARGIN_COMBINATION_LEG) {
    if (!!field->data) {
      CUstpFtdcMarginCombinationLegField *info = static_cast<CUstpFtdcMarginCombinationLegField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "CombInstrumentID", info->CombInstrumentID);
      SET_PROPERTY_STRING(env, obj, "LegInstrumentID", info->LegInstrumentID);
      SET_PROPERTY_NUMBER(env, obj, "Priority", info->Priority);
    };
  } else if (eventId == ON_RTN_MARGIN_COMB_ACTION) {
    if (!!field->data) {
      CUstpFtdcInputMarginCombActionField *info = static_cast<CUstpFtdcInputMarginCombActionField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_STRING(env, obj, "UserActionLocalID", info->UserActionLocalID);
      SET_PROPERTY_STRING(env, obj, "CombInstrumentID", info->CombInstrumentID);
      SET_PROPERTY_NUMBER(env, obj, "CombVolume", info->CombVolume);
      SET_PROPERTY_STRING(env, obj, "ActionLocalID", info->ActionLocalID);
    };
  } else if (eventId == ON_RTN_USER_DEPOSIT) {
    if (!!field->data) {
      CUstpFtdcstpUserDepositField *info = static_cast<CUstpFtdcstpUserDepositField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_NUMBER(env, obj, "Amount", info->Amount);
      SET_PROPERTY_STRING(env, obj, "UserOrderLocalID", info->UserOrderLocalID);
    };
  } else if (eventId == ON_RSP_QUERY_USER_LOGIN) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcRspUserLoginField *info = static_cast<CUstpFtdcRspUserLoginField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_STRING(env, obj, "LoginTime", info->LoginTime);
      SET_PROPERTY_STRING(env, obj, "ExchangeTime", info->ExchangeTime);
      SET_PROPERTY_STRING(env, obj, "MaxOrderLocalID", info->MaxOrderLocalID);
      SET_PROPERTY_BUFFER(env, obj, "TradingSystemName", info->TradingSystemName);
      SET_PROPERTY_NUMBER(env, obj, "DataCenterID", info->DataCenterID);
      SET_PROPERTY_NUMBER(env, obj, "PrivateFlowSize", info->PrivateFlowSize);
      SET_PROPERTY_NUMBER(env, obj, "UserFlowSize", info->UserFlowSize);
      SET_PROPERTY_STRING(env, obj, "ActionDay", info->ActionDay);
      SET_PROPERTY_STRING(env, obj, "FemasVersion", info->FemasVersion);
      SET_PROPERTY_NUMBER(env, obj, "FemasLifeCycle", info->FemasLifeCycle);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_QRY_ORDER) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcOrderField *info = static_cast<CUstpFtdcOrderField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "OrderSysID", info->OrderSysID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_NUMBER(env, obj, "SeatNo", info->SeatNo);
      SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
      SET_PROPERTY_STRING(env, obj, "UserOrderLocalID", info->UserOrderLocalID);
      SET_PROPERTY_NUMBER(env, obj, "LimitPrice", info->LimitPrice);
      SET_PROPERTY_NUMBER(env, obj, "Volume", info->Volume);
      SET_PROPERTY_STRING(env, obj, "GTDDate", info->GTDDate);
      SET_PROPERTY_NUMBER(env, obj, "MinVolume", info->MinVolume);
      SET_PROPERTY_NUMBER(env, obj, "StopPrice", info->StopPrice);
      SET_PROPERTY_NUMBER(env, obj, "IsAutoSuspend", info->IsAutoSuspend);
      SET_PROPERTY_STRING(env, obj, "BusinessUnit", info->BusinessUnit);
      SET_PROPERTY_STRING(env, obj, "UserCustom", info->UserCustom);
      SET_PROPERTY_NUMBER(env, obj, "BusinessLocalID", info->BusinessLocalID);
      SET_PROPERTY_STRING(env, obj, "ActionDay", info->ActionDay);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_STRING(env, obj, "ParticipantID", info->ParticipantID);
      SET_PROPERTY_STRING(env, obj, "OrderUserID", info->OrderUserID);
      SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
      SET_PROPERTY_STRING(env, obj, "SeatID", info->SeatID);
      SET_PROPERTY_STRING(env, obj, "InsertTime", info->InsertTime);
      SET_PROPERTY_STRING(env, obj, "OrderLocalID", info->OrderLocalID);
      SET_PROPERTY_STRING(env, obj, "CancelTime", info->CancelTime);
      SET_PROPERTY_STRING(env, obj, "CancelUserID", info->CancelUserID);
      SET_PROPERTY_NUMBER(env, obj, "VolumeTraded", info->VolumeTraded);
      SET_PROPERTY_NUMBER(env, obj, "VolumeRemain", info->VolumeRemain);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_QRY_TRADE) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcTradeField *info = static_cast<CUstpFtdcTradeField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_STRING(env, obj, "ParticipantID", info->ParticipantID);
      SET_PROPERTY_STRING(env, obj, "SeatID", info->SeatID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_STRING(env, obj, "OrderUserID", info->OrderUserID);
      SET_PROPERTY_STRING(env, obj, "TradeID", info->TradeID);
      SET_PROPERTY_STRING(env, obj, "OrderSysID", info->OrderSysID);
      SET_PROPERTY_STRING(env, obj, "UserOrderLocalID", info->UserOrderLocalID);
      SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
      SET_PROPERTY_NUMBER(env, obj, "TradePrice", info->TradePrice);
      SET_PROPERTY_NUMBER(env, obj, "TradeVolume", info->TradeVolume);
      SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
      SET_PROPERTY_STRING(env, obj, "ClearingPartID", info->ClearingPartID);
      SET_PROPERTY_NUMBER(env, obj, "UsedFee", info->UsedFee);
      SET_PROPERTY_NUMBER(env, obj, "UsedMargin", info->UsedMargin);
      SET_PROPERTY_NUMBER(env, obj, "Premium", info->Premium);
      SET_PROPERTY_NUMBER(env, obj, "Position", info->Position);
      SET_PROPERTY_NUMBER(env, obj, "PositionCost", info->PositionCost);
      SET_PROPERTY_NUMBER(env, obj, "Available", info->Available);
      SET_PROPERTY_NUMBER(env, obj, "Margin", info->Margin);
      SET_PROPERTY_NUMBER(env, obj, "FrozenMargin", info->FrozenMargin);
      SET_PROPERTY_NUMBER(env, obj, "BusinessLocalID", info->BusinessLocalID);
      SET_PROPERTY_STRING(env, obj, "ActionDay", info->ActionDay);
      SET_PROPERTY_STRING(env, obj, "ArbiInstrumentID", info->ArbiInstrumentID);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_QRY_USER_INVESTOR) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcRspUserInvestorField *info = static_cast<CUstpFtdcRspUserInvestorField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_QRY_TRADING_CODE) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcRspTradingCodeField *info = static_cast<CUstpFtdcRspTradingCodeField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_QRY_INVESTOR_ACCOUNT) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcRspInvestorAccountField *info = static_cast<CUstpFtdcRspInvestorAccountField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
      SET_PROPERTY_NUMBER(env, obj, "PreBalance", info->PreBalance);
      SET_PROPERTY_NUMBER(env, obj, "Deposit", info->Deposit);
      SET_PROPERTY_NUMBER(env, obj, "Withdraw", info->Withdraw);
      SET_PROPERTY_NUMBER(env, obj, "FrozenMargin", info->FrozenMargin);
      SET_PROPERTY_NUMBER(env, obj, "FrozenFee", info->FrozenFee);
      SET_PROPERTY_NUMBER(env, obj, "FrozenPremium", info->FrozenPremium);
      SET_PROPERTY_NUMBER(env, obj, "Fee", info->Fee);
      SET_PROPERTY_NUMBER(env, obj, "CloseProfit", info->CloseProfit);
      SET_PROPERTY_NUMBER(env, obj, "PositionProfit", info->PositionProfit);
      SET_PROPERTY_NUMBER(env, obj, "Available", info->Available);
      SET_PROPERTY_NUMBER(env, obj, "LongFrozenMargin", info->LongFrozenMargin);
      SET_PROPERTY_NUMBER(env, obj, "ShortFrozenMargin", info->ShortFrozenMargin);
      SET_PROPERTY_NUMBER(env, obj, "LongMargin", info->LongMargin);
      SET_PROPERTY_NUMBER(env, obj, "ShortMargin", info->ShortMargin);
      SET_PROPERTY_NUMBER(env, obj, "ReleaseMargin", info->ReleaseMargin);
      SET_PROPERTY_NUMBER(env, obj, "DynamicRights", info->DynamicRights);
      SET_PROPERTY_NUMBER(env, obj, "TodayInOut", info->TodayInOut);
      SET_PROPERTY_NUMBER(env, obj, "Margin", info->Margin);
      SET_PROPERTY_NUMBER(env, obj, "Premium", info->Premium);
      SET_PROPERTY_NUMBER(env, obj, "Risk", info->Risk);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_QRY_INSTRUMENT) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcRspInstrumentField *info = static_cast<CUstpFtdcRspInstrumentField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "ProductID", info->ProductID);
      SET_PROPERTY_BUFFER(env, obj, "ProductName", info->ProductName);
      SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
      SET_PROPERTY_BUFFER(env, obj, "InstrumentName", info->InstrumentName);
      SET_PROPERTY_NUMBER(env, obj, "DeliveryYear", info->DeliveryYear);
      SET_PROPERTY_NUMBER(env, obj, "DeliveryMonth", info->DeliveryMonth);
      SET_PROPERTY_NUMBER(env, obj, "MaxLimitOrderVolume", info->MaxLimitOrderVolume);
      SET_PROPERTY_NUMBER(env, obj, "MinLimitOrderVolume", info->MinLimitOrderVolume);
      SET_PROPERTY_NUMBER(env, obj, "MaxMarketOrderVolume", info->MaxMarketOrderVolume);
      SET_PROPERTY_NUMBER(env, obj, "MinMarketOrderVolume", info->MinMarketOrderVolume);
      SET_PROPERTY_NUMBER(env, obj, "VolumeMultiple", info->VolumeMultiple);
      SET_PROPERTY_NUMBER(env, obj, "PriceTick", info->PriceTick);
      SET_PROPERTY_NUMBER(env, obj, "LongPosLimit", info->LongPosLimit);
      SET_PROPERTY_NUMBER(env, obj, "ShortPosLimit", info->ShortPosLimit);
      SET_PROPERTY_NUMBER(env, obj, "LowerLimitPrice", info->LowerLimitPrice);
      SET_PROPERTY_NUMBER(env, obj, "UpperLimitPrice", info->UpperLimitPrice);
      SET_PROPERTY_NUMBER(env, obj, "PreSettlementPrice", info->PreSettlementPrice);
      SET_PROPERTY_STRING(env, obj, "CreateDate", info->CreateDate);
      SET_PROPERTY_STRING(env, obj, "OpenDate", info->OpenDate);
      SET_PROPERTY_STRING(env, obj, "ExpireDate", info->ExpireDate);
      SET_PROPERTY_STRING(env, obj, "StartDelivDate", info->StartDelivDate);
      SET_PROPERTY_STRING(env, obj, "EndDelivDate", info->EndDelivDate);
      SET_PROPERTY_NUMBER(env, obj, "BasisPrice", info->BasisPrice);
      SET_PROPERTY_NUMBER(env, obj, "IsTrading", info->IsTrading);
      SET_PROPERTY_STRING(env, obj, "UnderlyingInstrID", info->UnderlyingInstrID);
      SET_PROPERTY_NUMBER(env, obj, "UnderlyingMultiple", info->UnderlyingMultiple);
      SET_PROPERTY_NUMBER(env, obj, "StrikePrice", info->StrikePrice);
      SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_QRY_EXCHANGE) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcRspExchangeField *info = static_cast<CUstpFtdcRspExchangeField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_BUFFER(env, obj, "ExchangeName", info->ExchangeName);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_QRY_INVESTOR_POSITION) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcRspInvestorPositionField *info = static_cast<CUstpFtdcRspInvestorPositionField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
      SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
      SET_PROPERTY_NUMBER(env, obj, "UsedMargin", info->UsedMargin);
      SET_PROPERTY_NUMBER(env, obj, "Position", info->Position);
      SET_PROPERTY_NUMBER(env, obj, "PositionCost", info->PositionCost);
      SET_PROPERTY_NUMBER(env, obj, "YdPosition", info->YdPosition);
      SET_PROPERTY_NUMBER(env, obj, "YdPositionCost", info->YdPositionCost);
      SET_PROPERTY_NUMBER(env, obj, "FrozenMargin", info->FrozenMargin);
      SET_PROPERTY_NUMBER(env, obj, "FrozenPosition", info->FrozenPosition);
      SET_PROPERTY_NUMBER(env, obj, "FrozenClosing", info->FrozenClosing);
      SET_PROPERTY_NUMBER(env, obj, "YdFrozenClosing", info->YdFrozenClosing);
      SET_PROPERTY_NUMBER(env, obj, "FrozenPremium", info->FrozenPremium);
      SET_PROPERTY_STRING(env, obj, "LastTradeID", info->LastTradeID);
      SET_PROPERTY_STRING(env, obj, "LastOrderLocalID", info->LastOrderLocalID);
      SET_PROPERTY_NUMBER(env, obj, "SpeculationPosition", info->SpeculationPosition);
      SET_PROPERTY_NUMBER(env, obj, "ArbitragePosition", info->ArbitragePosition);
      SET_PROPERTY_NUMBER(env, obj, "HedgePosition", info->HedgePosition);
      SET_PROPERTY_NUMBER(env, obj, "SpecFrozenClosing", info->SpecFrozenClosing);
      SET_PROPERTY_NUMBER(env, obj, "HedgeFrozenClosing", info->HedgeFrozenClosing);
      SET_PROPERTY_STRING(env, obj, "Currency", info->Currency);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_SUBSCRIBE_TOPIC) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcDisseminationField *info = static_cast<CUstpFtdcDisseminationField *>(field->data);
      SET_PROPERTY_NUMBER(env, obj, "SequenceSeries", info->SequenceSeries);
      SET_PROPERTY_NUMBER(env, obj, "SequenceNo", info->SequenceNo);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_QRY_COMPLIANCE_PARAM) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcRspComplianceParamField *info = static_cast<CUstpFtdcRspComplianceParamField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
      SET_PROPERTY_NUMBER(env, obj, "DailyMaxOrder", info->DailyMaxOrder);
      SET_PROPERTY_NUMBER(env, obj, "DailyMaxOrderAction", info->DailyMaxOrderAction);
      SET_PROPERTY_NUMBER(env, obj, "DailyMaxErrorOrder", info->DailyMaxErrorOrder);
      SET_PROPERTY_NUMBER(env, obj, "DailyMaxOrderVolume", info->DailyMaxOrderVolume);
      SET_PROPERTY_NUMBER(env, obj, "DailyMaxOrderActionVolume", info->DailyMaxOrderActionVolume);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_QRY_TOPIC) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcDisseminationField *info = static_cast<CUstpFtdcDisseminationField *>(field->data);
      SET_PROPERTY_NUMBER(env, obj, "SequenceSeries", info->SequenceSeries);
      SET_PROPERTY_NUMBER(env, obj, "SequenceNo", info->SequenceNo);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_QRY_INVESTOR_FEE) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcInvestorFeeField *info = static_cast<CUstpFtdcInvestorFeeField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
      SET_PROPERTY_STRING(env, obj, "ProductID", info->ProductID);
      SET_PROPERTY_NUMBER(env, obj, "OpenFeeRate", info->OpenFeeRate);
      SET_PROPERTY_NUMBER(env, obj, "OpenFeeAmt", info->OpenFeeAmt);
      SET_PROPERTY_NUMBER(env, obj, "OffsetFeeRate", info->OffsetFeeRate);
      SET_PROPERTY_NUMBER(env, obj, "OffsetFeeAmt", info->OffsetFeeAmt);
      SET_PROPERTY_NUMBER(env, obj, "OTFeeRate", info->OTFeeRate);
      SET_PROPERTY_NUMBER(env, obj, "OTFeeAmt", info->OTFeeAmt);
      SET_PROPERTY_NUMBER(env, obj, "PerOrderAmt", info->PerOrderAmt);
      SET_PROPERTY_NUMBER(env, obj, "PerCancelAmt", info->PerCancelAmt);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_QRY_INVESTOR_MARGIN) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcInvestorMarginField *info = static_cast<CUstpFtdcInvestorMarginField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
      SET_PROPERTY_STRING(env, obj, "ProductID", info->ProductID);
      SET_PROPERTY_NUMBER(env, obj, "LongMarginRate", info->LongMarginRate);
      SET_PROPERTY_NUMBER(env, obj, "LongMarginAmt", info->LongMarginAmt);
      SET_PROPERTY_NUMBER(env, obj, "ShortMarginRate", info->ShortMarginRate);
      SET_PROPERTY_NUMBER(env, obj, "ShortMarginAmt", info->ShortMarginAmt);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_QRY_INVESTOR_COMB_POSITION) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcRspInvestorCombPositionField *info = static_cast<CUstpFtdcRspInvestorCombPositionField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
      SET_PROPERTY_STRING(env, obj, "CombInstrumentID", info->CombInstrumentID);
      SET_PROPERTY_NUMBER(env, obj, "CombPosition", info->CombPosition);
      SET_PROPERTY_NUMBER(env, obj, "CombFrozenPosition", info->CombFrozenPosition);
      SET_PROPERTY_NUMBER(env, obj, "CombFreeMargin", info->CombFreeMargin);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_QRY_INVESTOR_LEG_POSITION) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcRspInvestorLegPositionField *info = static_cast<CUstpFtdcRspInvestorLegPositionField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
      SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
      SET_PROPERTY_NUMBER(env, obj, "LongPosition", info->LongPosition);
      SET_PROPERTY_NUMBER(env, obj, "ShortPosition", info->ShortPosition);
      SET_PROPERTY_NUMBER(env, obj, "LongMargin", info->LongMargin);
      SET_PROPERTY_NUMBER(env, obj, "ShortMargin", info->ShortMargin);
      SET_PROPERTY_NUMBER(env, obj, "LongFrozenPosition", info->LongFrozenPosition);
      SET_PROPERTY_NUMBER(env, obj, "ShortFrozenPosition", info->ShortFrozenPosition);
      SET_PROPERTY_NUMBER(env, obj, "LongFrozenMargin", info->LongFrozenMargin);
      SET_PROPERTY_NUMBER(env, obj, "ShortFrozenMargin", info->ShortFrozenMargin);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_QRY_INSTRUMENT_GROUP) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcRspInstrumentGroupField *info = static_cast<CUstpFtdcRspInstrumentGroupField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
      SET_PROPERTY_STRING(env, obj, "InstrumentGroupID", info->InstrumentGroupID);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_QRY_CLIENT_MARGIN_COMB_TYPE) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcRspClientMarginCombTypeField *info = static_cast<CUstpFtdcRspClientMarginCombTypeField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "ParticipantID", info->ParticipantID);
      SET_PROPERTY_STRING(env, obj, "ClientID", info->ClientID);
      SET_PROPERTY_STRING(env, obj, "InstrumentGroupID", info->InstrumentGroupID);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_QRY_SYSTEM_TIME) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcRspQrySystemTimeField *info = static_cast<CUstpFtdcRspQrySystemTimeField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "SystemTime", info->SystemTime);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_CFMMC_TRADING_ACCOUNT_KEY) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcCFMMCTradingAccountKeyRspField *info = static_cast<CUstpFtdcCFMMCTradingAccountKeyRspField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "ParticipantID", info->ParticipantID);
      SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
      SET_PROPERTY_NUMBER(env, obj, "KeyID", info->KeyID);
      SET_PROPERTY_STRING(env, obj, "CurrentKey", info->CurrentKey);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_QRY_SETTLEMENT_INFO) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcSettlementRspField *info = static_cast<CUstpFtdcSettlementRspField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_NUMBER(env, obj, "SettlementID", info->SettlementID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_NUMBER(env, obj, "SequenceNo", info->SequenceNo);
      SET_PROPERTY_STRING(env, obj, "Content", info->Content);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_TRADING_ACCOUNT_PASSWORD_UPDATE) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcTradingAccountPasswordUpdateRspField *info = static_cast<CUstpFtdcTradingAccountPasswordUpdateRspField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_STRING(env, obj, "OldPassword", info->OldPassword);
      SET_PROPERTY_STRING(env, obj, "NewPassword", info->NewPassword);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_QRY_TRANSFER_BANK) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcTransferBankQryRspField *info = static_cast<CUstpFtdcTransferBankQryRspField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
      SET_PROPERTY_STRING(env, obj, "BankBrchID", info->BankBrchID);
      SET_PROPERTY_BUFFER(env, obj, "BankName", info->BankName);
      SET_PROPERTY_NUMBER(env, obj, "isActive", info->isActive);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_QRY_E_WARRANT_OFFSET) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcEWarrantOffsetFieldRspField *info = static_cast<CUstpFtdcEWarrantOffsetFieldRspField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
      SET_PROPERTY_NUMBER(env, obj, "Volume", info->Volume);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_QRY_TRANSFER_SERIA_OFFSET) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcTransferSerialFieldRspField *info = static_cast<CUstpFtdcTransferSerialFieldRspField *>(field->data);
      SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
      SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
      SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
      SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
      SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
      SET_PROPERTY_STRING(env, obj, "BankBrchID", info->BankBrchID);
      SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
      SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
      SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
      SET_PROPERTY_STRING(env, obj, "InvestorID", info->InvestorID);
      SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
      SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
      SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
      SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
      SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
      SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
      SET_PROPERTY_STRING(env, obj, "OperatorCode", info->OperatorCode);
      SET_PROPERTY_STRING(env, obj, "BankNewAccount", info->BankNewAccount);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_QRY_ACCOUNTREGISTER) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcAccountregisterRspField *info = static_cast<CUstpFtdcAccountregisterRspField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
      SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
      SET_PROPERTY_STRING(env, obj, "BankBrchID", info->BankBrchID);
      SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
      SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
      SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
      SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
      SET_PROPERTY_STRING(env, obj, "RegDate", info->RegDate);
      SET_PROPERTY_STRING(env, obj, "OutDate", info->OutDate);
      SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_QRY_CONTRACT_BANK) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcContractBankFieldRspField *info = static_cast<CUstpFtdcContractBankFieldRspField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
      SET_PROPERTY_STRING(env, obj, "BankBrchID", info->BankBrchID);
      SET_PROPERTY_BUFFER(env, obj, "BankName", info->BankName);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_FROM_BANK_TO_FUTURE_BY_FUTURE) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcTransferFieldReqField *info = static_cast<CUstpFtdcTransferFieldReqField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
      SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
      SET_PROPERTY_STRING(env, obj, "BankBrchID", info->BankBrchID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
      SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
      SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
      SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
      SET_PROPERTY_NUMBER(env, obj, "LastFragment", info->LastFragment);
      SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
      SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
      SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
      SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
      SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
      SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
      SET_PROPERTY_STRING(env, obj, "Password", info->Password);
      SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
      SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_NUMBER(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
      SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
      SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
      SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
      SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
      SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
      SET_PROPERTY_STRING(env, obj, "Message", info->Message);
      SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
      SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
      SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
      SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
      SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
      SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
      SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RTN_FROM_BANK_TO_FUTURE_BY_FUTURE) {
    if (!!field->data) {
      CUstpFtdcTransferFieldRtnField *info = static_cast<CUstpFtdcTransferFieldRtnField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
      SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
      SET_PROPERTY_STRING(env, obj, "BankBrchID", info->BankBrchID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
      SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
      SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
      SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
      SET_PROPERTY_NUMBER(env, obj, "LastFragment", info->LastFragment);
      SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
      SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
      SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
      SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
      SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
      SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
      SET_PROPERTY_STRING(env, obj, "Password", info->Password);
      SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
      SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_NUMBER(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
      SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
      SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
      SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
      SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
      SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
      SET_PROPERTY_STRING(env, obj, "Message", info->Message);
      SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
      SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
      SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
      SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
      SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
      SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
      SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
      SET_PROPERTY_STRING(env, obj, "ErrorMsg", info->ErrorMsg);
    };
  } else if (eventId == ON_ERR_RTN_FROM_BANK_TO_FUTURE_BY_FUTURE) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcTransferFieldReqField *info = static_cast<CUstpFtdcTransferFieldReqField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
      SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
      SET_PROPERTY_STRING(env, obj, "BankBrchID", info->BankBrchID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
      SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
      SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
      SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
      SET_PROPERTY_NUMBER(env, obj, "LastFragment", info->LastFragment);
      SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
      SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
      SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
      SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
      SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
      SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
      SET_PROPERTY_STRING(env, obj, "Password", info->Password);
      SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
      SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_NUMBER(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
      SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
      SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
      SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
      SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
      SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
      SET_PROPERTY_STRING(env, obj, "Message", info->Message);
      SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
      SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
      SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
      SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
      SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
      SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
      SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    };
  } else if (eventId == ON_RSP_FROM_FUTURE_TO_BANK_BY_FUTURE) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcTransferFieldReqField *info = static_cast<CUstpFtdcTransferFieldReqField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
      SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
      SET_PROPERTY_STRING(env, obj, "BankBrchID", info->BankBrchID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
      SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
      SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
      SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
      SET_PROPERTY_NUMBER(env, obj, "LastFragment", info->LastFragment);
      SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
      SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
      SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
      SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
      SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
      SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
      SET_PROPERTY_STRING(env, obj, "Password", info->Password);
      SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
      SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_NUMBER(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
      SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
      SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
      SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
      SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
      SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
      SET_PROPERTY_STRING(env, obj, "Message", info->Message);
      SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
      SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
      SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
      SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
      SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
      SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
      SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RTN_FROM_FUTURE_TO_BANK_BY_BANK) {
    if (!!field->data) {
      CUstpFtdcTransferFieldRtnField *info = static_cast<CUstpFtdcTransferFieldRtnField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
      SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
      SET_PROPERTY_STRING(env, obj, "BankBrchID", info->BankBrchID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
      SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
      SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
      SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
      SET_PROPERTY_NUMBER(env, obj, "LastFragment", info->LastFragment);
      SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
      SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
      SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
      SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
      SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
      SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
      SET_PROPERTY_STRING(env, obj, "Password", info->Password);
      SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
      SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_NUMBER(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
      SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
      SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
      SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
      SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
      SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
      SET_PROPERTY_STRING(env, obj, "Message", info->Message);
      SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
      SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
      SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
      SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
      SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
      SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
      SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
      SET_PROPERTY_STRING(env, obj, "ErrorMsg", info->ErrorMsg);
    };
  } else if (eventId == ON_ERR_RTN_FROM_FUTURE_TO_BANK_BY_BANK) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcTransferFieldReqField *info = static_cast<CUstpFtdcTransferFieldReqField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
      SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
      SET_PROPERTY_STRING(env, obj, "BankBrchID", info->BankBrchID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
      SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
      SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
      SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
      SET_PROPERTY_NUMBER(env, obj, "LastFragment", info->LastFragment);
      SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
      SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
      SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
      SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
      SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
      SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
      SET_PROPERTY_STRING(env, obj, "Password", info->Password);
      SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
      SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_NUMBER(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
      SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
      SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
      SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
      SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
      SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
      SET_PROPERTY_STRING(env, obj, "Message", info->Message);
      SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
      SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
      SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
      SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
      SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
      SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
      SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    };
  } else if (eventId == ON_RTN_FROM_BANK_TO_FUTURE_BY_BANK) {
    if (!!field->data) {
      CUstpFtdcTransferFieldRtnField *info = static_cast<CUstpFtdcTransferFieldRtnField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
      SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
      SET_PROPERTY_STRING(env, obj, "BankBrchID", info->BankBrchID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
      SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
      SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
      SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
      SET_PROPERTY_NUMBER(env, obj, "LastFragment", info->LastFragment);
      SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
      SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
      SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
      SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
      SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
      SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
      SET_PROPERTY_STRING(env, obj, "Password", info->Password);
      SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
      SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_NUMBER(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
      SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
      SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
      SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
      SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
      SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
      SET_PROPERTY_STRING(env, obj, "Message", info->Message);
      SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
      SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
      SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
      SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
      SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
      SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
      SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
      SET_PROPERTY_STRING(env, obj, "ErrorMsg", info->ErrorMsg);
    };
  } else if (eventId == ON_RSP_QUERY_BANK_ACCOUNT_MONEY_BY_FUTURE) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcAccountFieldReqField *info = static_cast<CUstpFtdcAccountFieldReqField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
      SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
      SET_PROPERTY_STRING(env, obj, "BankBrchID", info->BankBrchID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
      SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
      SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
      SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
      SET_PROPERTY_NUMBER(env, obj, "LastFragment", info->LastFragment);
      SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
      SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
      SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
      SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
      SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
      SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
      SET_PROPERTY_STRING(env, obj, "Password", info->Password);
      SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
      SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_NUMBER(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
      SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
      SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
      SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
      SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
      SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
      SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
      SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
      SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RTN_QUERY_BANK_BALANCE_BY_FUTURE) {
    if (!!field->data) {
      CUstpFtdcAccountFieldRtnField *info = static_cast<CUstpFtdcAccountFieldRtnField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
      SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
      SET_PROPERTY_STRING(env, obj, "BankBrchID", info->BankBrchID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
      SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
      SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
      SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
      SET_PROPERTY_NUMBER(env, obj, "LastFragment", info->LastFragment);
      SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
      SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
      SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
      SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
      SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
      SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
      SET_PROPERTY_STRING(env, obj, "Password", info->Password);
      SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
      SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_NUMBER(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
      SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
      SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
      SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
      SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
      SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
      SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
      SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
      SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
      SET_PROPERTY_NUMBER(env, obj, "BankUseAmount", info->BankUseAmount);
      SET_PROPERTY_NUMBER(env, obj, "BankFetchAmount", info->BankFetchAmount);
    };
  } else if (eventId == ON_ERR_RTN_QUERY_BANK_BALANCE_BY_FUTURE) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcAccountFieldReqField *info = static_cast<CUstpFtdcAccountFieldReqField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
      SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
      SET_PROPERTY_STRING(env, obj, "BankBrchID", info->BankBrchID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
      SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
      SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
      SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
      SET_PROPERTY_NUMBER(env, obj, "LastFragment", info->LastFragment);
      SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
      SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
      SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
      SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
      SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
      SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
      SET_PROPERTY_STRING(env, obj, "Password", info->Password);
      SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
      SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_NUMBER(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
      SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
      SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
      SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
      SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
      SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
      SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
      SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
      SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    };
  } else if (eventId == ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_BANK) {
    if (!!field->data) {
      CUstpFtdcRepealFieldRtnField *info = static_cast<CUstpFtdcRepealFieldRtnField *>(field->data);
      SET_PROPERTY_NUMBER(env, obj, "RepealTimeInterval", info->RepealTimeInterval);
      SET_PROPERTY_NUMBER(env, obj, "RepealedTimes", info->RepealedTimes);
      SET_PROPERTY_NUMBER(env, obj, "PlateRepealSerial", info->PlateRepealSerial);
      SET_PROPERTY_STRING(env, obj, "BankRepealSerial", info->BankRepealSerial);
      SET_PROPERTY_NUMBER(env, obj, "FutureRepealSerial", info->FutureRepealSerial);
      SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
      SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
      SET_PROPERTY_STRING(env, obj, "BankBrchID", info->BankBrchID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
      SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
      SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
      SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
      SET_PROPERTY_NUMBER(env, obj, "LastFragment", info->LastFragment);
      SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
      SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
      SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
      SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
      SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
      SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
      SET_PROPERTY_STRING(env, obj, "Password", info->Password);
      SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
      SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_NUMBER(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
      SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
      SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
      SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
      SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
      SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
      SET_PROPERTY_STRING(env, obj, "Message", info->Message);
      SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
      SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
      SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
      SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
      SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
      SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
      SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
      SET_PROPERTY_STRING(env, obj, "ErrorMsg", info->ErrorMsg);
    };
  } else if (eventId == ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_BANK) {
    if (!!field->data) {
      CUstpFtdcRepealFieldRtnField *info = static_cast<CUstpFtdcRepealFieldRtnField *>(field->data);
      SET_PROPERTY_NUMBER(env, obj, "RepealTimeInterval", info->RepealTimeInterval);
      SET_PROPERTY_NUMBER(env, obj, "RepealedTimes", info->RepealedTimes);
      SET_PROPERTY_NUMBER(env, obj, "PlateRepealSerial", info->PlateRepealSerial);
      SET_PROPERTY_STRING(env, obj, "BankRepealSerial", info->BankRepealSerial);
      SET_PROPERTY_NUMBER(env, obj, "FutureRepealSerial", info->FutureRepealSerial);
      SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
      SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
      SET_PROPERTY_STRING(env, obj, "BankBrchID", info->BankBrchID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
      SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
      SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
      SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
      SET_PROPERTY_NUMBER(env, obj, "LastFragment", info->LastFragment);
      SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
      SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
      SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
      SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
      SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
      SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
      SET_PROPERTY_STRING(env, obj, "Password", info->Password);
      SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
      SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_NUMBER(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
      SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
      SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
      SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
      SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
      SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
      SET_PROPERTY_STRING(env, obj, "Message", info->Message);
      SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
      SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
      SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
      SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
      SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
      SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
      SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
      SET_PROPERTY_STRING(env, obj, "ErrorMsg", info->ErrorMsg);
    };
  } else if (eventId == ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_FUTURE_MANUAL) {
    if (!!field->data) {
      CUstpFtdcRepealFieldRtnField *info = static_cast<CUstpFtdcRepealFieldRtnField *>(field->data);
      SET_PROPERTY_NUMBER(env, obj, "RepealTimeInterval", info->RepealTimeInterval);
      SET_PROPERTY_NUMBER(env, obj, "RepealedTimes", info->RepealedTimes);
      SET_PROPERTY_NUMBER(env, obj, "PlateRepealSerial", info->PlateRepealSerial);
      SET_PROPERTY_STRING(env, obj, "BankRepealSerial", info->BankRepealSerial);
      SET_PROPERTY_NUMBER(env, obj, "FutureRepealSerial", info->FutureRepealSerial);
      SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
      SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
      SET_PROPERTY_STRING(env, obj, "BankBrchID", info->BankBrchID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
      SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
      SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
      SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
      SET_PROPERTY_NUMBER(env, obj, "LastFragment", info->LastFragment);
      SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
      SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
      SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
      SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
      SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
      SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
      SET_PROPERTY_STRING(env, obj, "Password", info->Password);
      SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
      SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_NUMBER(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
      SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
      SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
      SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
      SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
      SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
      SET_PROPERTY_STRING(env, obj, "Message", info->Message);
      SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
      SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
      SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
      SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
      SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
      SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
      SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
      SET_PROPERTY_STRING(env, obj, "ErrorMsg", info->ErrorMsg);
    };
  } else if (eventId == ON_ERR_RTN_REPEAL_BANK_TO_FUTURE_BY_FUTURE_MANUAL) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcRepealFieldRspField *info = static_cast<CUstpFtdcRepealFieldRspField *>(field->data);
      SET_PROPERTY_NUMBER(env, obj, "RepealTimeInterval", info->RepealTimeInterval);
      SET_PROPERTY_NUMBER(env, obj, "RepealedTimes", info->RepealedTimes);
      SET_PROPERTY_NUMBER(env, obj, "PlateRepealSerial", info->PlateRepealSerial);
      SET_PROPERTY_STRING(env, obj, "BankRepealSerial", info->BankRepealSerial);
      SET_PROPERTY_NUMBER(env, obj, "FutureRepealSerial", info->FutureRepealSerial);
      SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
      SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
      SET_PROPERTY_STRING(env, obj, "BankBrchID", info->BankBrchID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
      SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
      SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
      SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
      SET_PROPERTY_NUMBER(env, obj, "LastFragment", info->LastFragment);
      SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
      SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
      SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
      SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
      SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
      SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
      SET_PROPERTY_STRING(env, obj, "Password", info->Password);
      SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
      SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_NUMBER(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
      SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
      SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
      SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
      SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
      SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
      SET_PROPERTY_STRING(env, obj, "Message", info->Message);
      SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
      SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
      SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
      SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
      SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
      SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
      SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    };
  } else if (eventId == ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_FUTURE_MANUAL) {
    if (!!field->data) {
      CUstpFtdcRepealFieldRtnField *info = static_cast<CUstpFtdcRepealFieldRtnField *>(field->data);
      SET_PROPERTY_NUMBER(env, obj, "RepealTimeInterval", info->RepealTimeInterval);
      SET_PROPERTY_NUMBER(env, obj, "RepealedTimes", info->RepealedTimes);
      SET_PROPERTY_NUMBER(env, obj, "PlateRepealSerial", info->PlateRepealSerial);
      SET_PROPERTY_STRING(env, obj, "BankRepealSerial", info->BankRepealSerial);
      SET_PROPERTY_NUMBER(env, obj, "FutureRepealSerial", info->FutureRepealSerial);
      SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
      SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
      SET_PROPERTY_STRING(env, obj, "BankBrchID", info->BankBrchID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
      SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
      SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
      SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
      SET_PROPERTY_NUMBER(env, obj, "LastFragment", info->LastFragment);
      SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
      SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
      SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
      SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
      SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
      SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
      SET_PROPERTY_STRING(env, obj, "Password", info->Password);
      SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
      SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_NUMBER(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
      SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
      SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
      SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
      SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
      SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
      SET_PROPERTY_STRING(env, obj, "Message", info->Message);
      SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
      SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
      SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
      SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
      SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
      SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
      SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
      SET_PROPERTY_STRING(env, obj, "ErrorMsg", info->ErrorMsg);
    };
  } else if (eventId == ON_ERR_RTN_REPEAL_FUTURE_TO_BANK_BY_FUTURE_MANUAL) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcRepealFieldRspField *info = static_cast<CUstpFtdcRepealFieldRspField *>(field->data);
      SET_PROPERTY_NUMBER(env, obj, "RepealTimeInterval", info->RepealTimeInterval);
      SET_PROPERTY_NUMBER(env, obj, "RepealedTimes", info->RepealedTimes);
      SET_PROPERTY_NUMBER(env, obj, "PlateRepealSerial", info->PlateRepealSerial);
      SET_PROPERTY_STRING(env, obj, "BankRepealSerial", info->BankRepealSerial);
      SET_PROPERTY_NUMBER(env, obj, "FutureRepealSerial", info->FutureRepealSerial);
      SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
      SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
      SET_PROPERTY_STRING(env, obj, "BankBrchID", info->BankBrchID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
      SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
      SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
      SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
      SET_PROPERTY_NUMBER(env, obj, "LastFragment", info->LastFragment);
      SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
      SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
      SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
      SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
      SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
      SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
      SET_PROPERTY_STRING(env, obj, "Password", info->Password);
      SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
      SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_NUMBER(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
      SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
      SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
      SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
      SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
      SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
      SET_PROPERTY_STRING(env, obj, "Message", info->Message);
      SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
      SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
      SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
      SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
      SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
      SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
      SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
    };
  } else if (eventId == ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_FUTURE) {
    if (!!field->data) {
      CUstpFtdcRepealFieldRtnField *info = static_cast<CUstpFtdcRepealFieldRtnField *>(field->data);
      SET_PROPERTY_NUMBER(env, obj, "RepealTimeInterval", info->RepealTimeInterval);
      SET_PROPERTY_NUMBER(env, obj, "RepealedTimes", info->RepealedTimes);
      SET_PROPERTY_NUMBER(env, obj, "PlateRepealSerial", info->PlateRepealSerial);
      SET_PROPERTY_STRING(env, obj, "BankRepealSerial", info->BankRepealSerial);
      SET_PROPERTY_NUMBER(env, obj, "FutureRepealSerial", info->FutureRepealSerial);
      SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
      SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
      SET_PROPERTY_STRING(env, obj, "BankBrchID", info->BankBrchID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
      SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
      SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
      SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
      SET_PROPERTY_NUMBER(env, obj, "LastFragment", info->LastFragment);
      SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
      SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
      SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
      SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
      SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
      SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
      SET_PROPERTY_STRING(env, obj, "Password", info->Password);
      SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
      SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_NUMBER(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
      SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
      SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
      SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
      SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
      SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
      SET_PROPERTY_STRING(env, obj, "Message", info->Message);
      SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
      SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
      SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
      SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
      SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
      SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
      SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
      SET_PROPERTY_STRING(env, obj, "ErrorMsg", info->ErrorMsg);
    };
  } else if (eventId == ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_FUTURE) {
    if (!!field->data) {
      CUstpFtdcRepealFieldRtnField *info = static_cast<CUstpFtdcRepealFieldRtnField *>(field->data);
      SET_PROPERTY_NUMBER(env, obj, "RepealTimeInterval", info->RepealTimeInterval);
      SET_PROPERTY_NUMBER(env, obj, "RepealedTimes", info->RepealedTimes);
      SET_PROPERTY_NUMBER(env, obj, "PlateRepealSerial", info->PlateRepealSerial);
      SET_PROPERTY_STRING(env, obj, "BankRepealSerial", info->BankRepealSerial);
      SET_PROPERTY_NUMBER(env, obj, "FutureRepealSerial", info->FutureRepealSerial);
      SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
      SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
      SET_PROPERTY_STRING(env, obj, "BankBrchID", info->BankBrchID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
      SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
      SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
      SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
      SET_PROPERTY_NUMBER(env, obj, "LastFragment", info->LastFragment);
      SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
      SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
      SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
      SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
      SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
      SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
      SET_PROPERTY_STRING(env, obj, "Password", info->Password);
      SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
      SET_PROPERTY_NUMBER(env, obj, "FutureSerial", info->FutureSerial);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_NUMBER(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
      SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
      SET_PROPERTY_NUMBER(env, obj, "TradeAmount", info->TradeAmount);
      SET_PROPERTY_NUMBER(env, obj, "FutureFetchAmount", info->FutureFetchAmount);
      SET_PROPERTY_NUMBER(env, obj, "CustFee", info->CustFee);
      SET_PROPERTY_NUMBER(env, obj, "BrokerFee", info->BrokerFee);
      SET_PROPERTY_STRING(env, obj, "Message", info->Message);
      SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
      SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
      SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
      SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
      SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
      SET_PROPERTY_NUMBER(env, obj, "RequestID", info->RequestID);
      SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
      SET_PROPERTY_STRING(env, obj, "ErrorMsg", info->ErrorMsg);
    };
  } else if (eventId == ON_RTN_OPEN_ACCOUNT_BY_BANK) {
    if (!!field->data) {
      CUstpFtdcAccountFieldField *info = static_cast<CUstpFtdcAccountFieldField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
      SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
      SET_PROPERTY_STRING(env, obj, "BankBrchID", info->BankBrchID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
      SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
      SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
      SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
      SET_PROPERTY_NUMBER(env, obj, "LastFragment", info->LastFragment);
      SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
      SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
      SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
      SET_PROPERTY_STRING(env, obj, "CountryCode", info->CountryCode);
      SET_PROPERTY_STRING(env, obj, "Address", info->Address);
      SET_PROPERTY_STRING(env, obj, "ZipCode", info->ZipCode);
      SET_PROPERTY_STRING(env, obj, "Telephone", info->Telephone);
      SET_PROPERTY_STRING(env, obj, "MobilePhone", info->MobilePhone);
      SET_PROPERTY_STRING(env, obj, "Fax", info->Fax);
      SET_PROPERTY_STRING(env, obj, "EMail", info->EMail);
      SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
      SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
      SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
      SET_PROPERTY_STRING(env, obj, "Password", info->Password);
      SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
      SET_PROPERTY_NUMBER(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
      SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
      SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
      SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
      SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
      SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
      SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
      SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
      SET_PROPERTY_STRING(env, obj, "ErrorMsg", info->ErrorMsg);
    };
  } else if (eventId == ON_RTN_CANCEL_ACCOUNT_BY_BANK) {
    if (!!field->data) {
      CUstpFtdcAccountFieldField *info = static_cast<CUstpFtdcAccountFieldField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
      SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
      SET_PROPERTY_STRING(env, obj, "BankBrchID", info->BankBrchID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
      SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
      SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
      SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
      SET_PROPERTY_NUMBER(env, obj, "LastFragment", info->LastFragment);
      SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
      SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
      SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
      SET_PROPERTY_STRING(env, obj, "CountryCode", info->CountryCode);
      SET_PROPERTY_STRING(env, obj, "Address", info->Address);
      SET_PROPERTY_STRING(env, obj, "ZipCode", info->ZipCode);
      SET_PROPERTY_STRING(env, obj, "Telephone", info->Telephone);
      SET_PROPERTY_STRING(env, obj, "MobilePhone", info->MobilePhone);
      SET_PROPERTY_STRING(env, obj, "Fax", info->Fax);
      SET_PROPERTY_STRING(env, obj, "EMail", info->EMail);
      SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
      SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
      SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
      SET_PROPERTY_STRING(env, obj, "Password", info->Password);
      SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
      SET_PROPERTY_NUMBER(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
      SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
      SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
      SET_PROPERTY_STRING(env, obj, "DeviceID", info->DeviceID);
      SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
      SET_PROPERTY_STRING(env, obj, "BankSecuAcc", info->BankSecuAcc);
      SET_PROPERTY_STRING(env, obj, "OperNo", info->OperNo);
      SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
      SET_PROPERTY_STRING(env, obj, "ErrorMsg", info->ErrorMsg);
    };
  } else if (eventId == ON_RTN_CHANGE_ACCOUNT_BY_BANK) {
    if (!!field->data) {
      CUstpFtdcChangeAccountFieldField *info = static_cast<CUstpFtdcChangeAccountFieldField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "TradeCode", info->TradeCode);
      SET_PROPERTY_STRING(env, obj, "BankID", info->BankID);
      SET_PROPERTY_STRING(env, obj, "BankBrchID", info->BankBrchID);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "BrokerBranchID", info->BrokerBranchID);
      SET_PROPERTY_STRING(env, obj, "TradeDate", info->TradeDate);
      SET_PROPERTY_STRING(env, obj, "TradeTime", info->TradeTime);
      SET_PROPERTY_STRING(env, obj, "BankSerial", info->BankSerial);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_NUMBER(env, obj, "PlateSerial", info->PlateSerial);
      SET_PROPERTY_NUMBER(env, obj, "LastFragment", info->LastFragment);
      SET_PROPERTY_NUMBER(env, obj, "SessionID", info->SessionID);
      SET_PROPERTY_BUFFER(env, obj, "CustomerName", info->CustomerName);
      SET_PROPERTY_STRING(env, obj, "IdentifiedCardNo", info->IdentifiedCardNo);
      SET_PROPERTY_STRING(env, obj, "CountryCode", info->CountryCode);
      SET_PROPERTY_STRING(env, obj, "Address", info->Address);
      SET_PROPERTY_STRING(env, obj, "ZipCode", info->ZipCode);
      SET_PROPERTY_STRING(env, obj, "Telephone", info->Telephone);
      SET_PROPERTY_STRING(env, obj, "MobilePhone", info->MobilePhone);
      SET_PROPERTY_STRING(env, obj, "Fax", info->Fax);
      SET_PROPERTY_STRING(env, obj, "EMail", info->EMail);
      SET_PROPERTY_STRING(env, obj, "BankAccount", info->BankAccount);
      SET_PROPERTY_STRING(env, obj, "BankPassWord", info->BankPassWord);
      SET_PROPERTY_STRING(env, obj, "NewBankAccount", info->NewBankAccount);
      SET_PROPERTY_STRING(env, obj, "NewBankPassWord", info->NewBankPassWord);
      SET_PROPERTY_STRING(env, obj, "AccountID", info->AccountID);
      SET_PROPERTY_STRING(env, obj, "Password", info->Password);
      SET_PROPERTY_NUMBER(env, obj, "InstallID", info->InstallID);
      SET_PROPERTY_NUMBER(env, obj, "VerifyCertNoFlag", info->VerifyCertNoFlag);
      SET_PROPERTY_STRING(env, obj, "CurrencyID", info->CurrencyID);
      SET_PROPERTY_STRING(env, obj, "Digest", info->Digest);
      SET_PROPERTY_STRING(env, obj, "BrokerIDByBank", info->BrokerIDByBank);
      SET_PROPERTY_NUMBER(env, obj, "TID", info->TID);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", info->ErrorID);
      SET_PROPERTY_STRING(env, obj, "ErrorMsg", info->ErrorMsg);
    };
  }

  if (cbMap.find(eventId) != cbMap.end()) {
    cbMap.find(eventId)->second->Value().Call({env.Null(), obj});
  }

  // delete req->data;
  delete req;
};