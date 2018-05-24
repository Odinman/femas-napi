const _ = require('lodash');
const fs = require('fs');

let str = `	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
	virtual void OnFrontConnected(){};
	
	///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
	///@param nReason 错误原因
	///        0x1001 网络读失败
	///        0x1002 网络写失败
	///        0x2001 接收心跳超时
	///        0x2002 发送心跳失败
	///        0x2003 收到错误报文
	virtual void OnFrontDisconnected(int nReason){};
		
	///心跳超时警告。当长时间未收到报文时，该方法被调用。
	///@param nTimeLapse 距离上次接收报文的时间
	virtual void OnHeartBeatWarning(int nTimeLapse){};
	
	///报文回调开始通知。当API收到一个报文后，首先调用本方法，然后是各数据域的回调，最后是报文回调结束通知。
	///@param nTopicID 主题代码（如私有流、公共流、行情流等）
	///@param nSequenceNo 报文序号
	virtual void OnPackageStart(int nTopicID, int nSequenceNo){};
	
	///报文回调结束通知。当API收到一个报文后，首先调用报文回调开始通知，然后是各数据域的回调，最后调用本方法。
	///@param nTopicID 主题代码（如私有流、公共流、行情流等）
	///@param nSequenceNo 报文序号
	virtual void OnPackageEnd(int nTopicID, int nSequenceNo){};


	///错误应答
	virtual void OnRspError(CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///风控前置系统用户登录应答
	virtual void OnRspUserLogin(CUstpFtdcRspUserLoginField *pRspUserLogin, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户退出应答
	virtual void OnRspUserLogout(CUstpFtdcRspUserLogoutField *pRspUserLogout, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///订阅主题应答
	virtual void OnRspSubscribeTopic(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///主题查询应答
	virtual void OnRspQryTopic(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///深度行情通知
	virtual void OnRtnDepthMarketData(CUstpFtdcDepthMarketDataField *pDepthMarketData) {};

	///订阅合约的相关信息
	virtual void OnRspSubMarketData(CUstpFtdcSpecificInstrumentField *pSpecificInstrument, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///退订合约的相关信息
	virtual void OnRspUnSubMarketData(CUstpFtdcSpecificInstrumentField *pSpecificInstrument, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///获取行情主题信息应答
	virtual void OnRspGetMarketTopic(CUstpFtdcRspMarketTopicField *pRspMarketTopic, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
`;

let generateBindEvent = function () {
  let reg = /^\s*virtual\svoid\s([a-zA-Z]*)/;
  let printLine = (line) => {
    let arr = line.match(reg);
    let e = arr[1];
    let eventName = _.camelCase(e.replace("On", ""));
    let val = _.replace(_.upperCase(_.snakeCase(e)), /\s/g, "_");
    console.log(`eventMap["${eventName}"] = ${val};`);
  };

  str.split("\n").forEach((line) => {
    if (line.match(reg)) {
      printLine(line)
    }
  });
};

let eventConst = require('./event-const') || {};
let maxEventId, eventArr = [];
for (let key in eventConst) {
  eventArr.push(eventConst[key]);
}
maxEventId = Math.max.apply(null, eventArr);
console.log('[DEBUG] maxEventId:', maxEventId++);

let generateEventConst = function () {
  let reg = /^\s*virtual\svoid\s([a-zA-Z]*)/;
  let printLine = (line) => {
    let arr = line.match(reg);
    let e = arr[1];
    let eventName = _.camelCase(e.replace("On", ""));
    let eventConstName = _.replace(_.upperCase(_.snakeCase(e)), /\s/g, "_");
    if (!eventConst[eventConstName]) {
      eventConst[eventConstName] = (maxEventId++);
    }
    console.log(`#define ${eventConstName} ${eventConst[eventConstName]}`);
  };

  str.split("\n").forEach((line) => {
    if (line.match(reg)) {
      printLine(line)
    }
  });
  fs.writeFileSync('./event-const.json', JSON.stringify(eventConst));
};


generateBindEvent();
// generateEventConst();