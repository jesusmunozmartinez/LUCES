//************************************************************
// Author: Jesús Muñoz Martínez
// Proyect: Trabajo Fin de Master: LUCES.
// Master de Sistemas Electrónicos para Entornos Inteligentes
// Root Node.
// Description: script.js file
//
//************************************************************


var gateway = `ws://${window.location.hostname}/ws`;
var websocket;
window.addEventListener('load', onload);


function onload(event) {
	createTbody();
    hideShow();
    initWebSocket();
}


function getConfigValues(){  
    var msg = {
        type: "getConfig"
       };
    websocket.send(JSON.stringify(msg));
}


function initWebSocket() {
    console.log('Trying to open a WebSocket connection…');
    websocket = new WebSocket(gateway);
    websocket.onopen = onOpen;
    websocket.onclose = onClose;
    websocket.onmessage = onMessage;
}

function onOpen(event) {
    console.log('Connection opened');
    getConfigValues();
}

function onClose(event) {
    console.log('Connection closed');
    setTimeout(initWebSocket, 2000);
}


// function runs when you move the sliders.
function updateValue(element) {
    var sliderNumber = element.id.charAt(element.id.length-1);
    var sliderValue = document.getElementById(element.id).value;

    if (sliderNumber == 1 || sliderNumber == 4 || sliderNumber == 7){//bVal
        document.getElementById("sliderValue1").innerHTML = sliderValue;
		document.getElementById("slider1".toString()).value = sliderValue;
        document.getElementById("sliderValue4").innerHTML = sliderValue;
		document.getElementById("slider4".toString()).value = sliderValue;
		document.getElementById("sliderValue7").innerHTML = sliderValue;
		document.getElementById("slider7".toString()).value = sliderValue;
    }else if (sliderNumber == 2 || sliderNumber == 5 || sliderNumber == 6 || sliderNumber == 8 || sliderNumber == 9){//bPre
        document.getElementById("sliderValue2").innerHTML = sliderValue;
        document.getElementById("sliderValue5").innerHTML = sliderValue;
        document.getElementById("sliderValue6").innerHTML = sliderValue;
		document.getElementById("sliderValue8").innerHTML = sliderValue;
        document.getElementById("sliderValue9").innerHTML = sliderValue;
		document.getElementById("slider2".toString()).value = sliderValue;
		document.getElementById("slider5".toString()).value = sliderValue;
		document.getElementById("slider6".toString()).value = sliderValue;
		document.getElementById("slider8".toString()).value = sliderValue;
		document.getElementById("slider9".toString()).value = sliderValue;
    }else if (sliderNumber == 3){//mLum
        document.getElementById("sliderValue3").innerHTML = sliderValue;
		document.getElementById("slider3".toString()).value = sliderValue;
    }
    sendpValues();
}
    
function updateLux(element) {
    var elemNumber = element.id.charAt(element.id.length-1);
    var elemValue = document.getElementById(element.id).value;
    if (elemNumber == 1 || elemNumber == 4 ){
		document.getElementById("bTLux1").value = elemValue;
		document.getElementById("bTLux4").value = elemValue;
    }else if (elemNumber == 2 || elemNumber == 5){
        document.getElementById("bTLux2").value = elemValue;
		document.getElementById("bTLux5").value = elemValue;
    }else if (elemNumber == 3 || elemNumber == 6){
        document.getElementById("bTLux3").value = elemValue;
		document.getElementById("bTLux6").value = elemValue;
    }
    sendpValues();
}



function updateOnOff(element) {
    var elemNumber = element.id.charAt(element.id.length-1);
    var elemValue = document.getElementById(element.id).value;
    if (elemNumber == 1 || elemNumber == 4){
		document.getElementById("bTon1").value = elemValue;
		document.getElementById("timeOn4").value = elemValue;
        document.getElementById("bTTon6").value = elemValue;
    }else if (elemNumber == 2 || elemNumber == 5){
        document.getElementById("bToff2").value = elemValue;
		document.getElementById("timeOff5").value = elemValue;
        document.getElementById("bTToff7").value = elemValue;
    }
    sendpValues();
}

function update(element) {
    var elemNumber = element.id.charAt(element.id.length-1);
    var elemValue = document.getElementById(element.id).value;

    if (elemNumber == 2 || elemNumber == 6 ){
		document.getElementById("bT1_1").value = elemValue;
		document.getElementById("bT1_2").value = elemValue;
        document.getElementById("bT1_5").value = elemValue;
        document.getElementById("bT1_6").value = elemValue;
    }else if (elemNumber == 4 || elemNumber == 8){
		document.getElementById("bT2_3").value = elemValue;
		document.getElementById("bT2_4").value = elemValue;
        document.getElementById("bT2_7").value = elemValue;
        document.getElementById("bT2_8").value = elemValue;
    }
    sendpValues();
}
  
// handle the messages received via websocket protocol 
function onMessage(event) { 
 
	var myObj = JSON.parse(event.data); 
    if (myObj['type']=='S'){ //messagge from nodes
        updateInfoTable(event);
    }

    if(myObj['type']=='pValues' || myObj['type']=='config'){  
        document.getElementById("statusOnOff").innerHTML = myObj["mOn"];  
        document.getElementById("slider1".toString()).value = myObj["bVal"];
        document.getElementById("sliderValue1").innerHTML = myObj["bVal"];  //value
        document.getElementById("slider2".toString()).value = myObj["bPre"];
        document.getElementById("sliderValue2").innerHTML = myObj["bPre"];  //value
        document.getElementById("slider3".toString()).value = myObj["mLux"];
        document.getElementById("sliderValue3").innerHTML = myObj["mLux"];  //value
        document.getElementById("slider4".toString()).value = myObj["bVal"];
        document.getElementById("sliderValue4").innerHTML = myObj["bVal"];  //value
        document.getElementById("slider5".toString()).value = myObj["bPre"];
        document.getElementById("sliderValue5").innerHTML = myObj["bPre"];  //value
        document.getElementById("slider6".toString()).value = myObj["bPre"];
        document.getElementById("sliderValue6").innerHTML = myObj["bPre"];  //value
		document.getElementById("slider7".toString()).value = myObj["bVal"];
        document.getElementById("sliderValue7").innerHTML = myObj["bVal"];  //value
        document.getElementById("slider8".toString()).value = myObj["bPre"];
        document.getElementById("sliderValue8").innerHTML = myObj["bPre"];  //value
        document.getElementById("slider9".toString()).value = myObj["bPre"];
        document.getElementById("sliderValue9").innerHTML = myObj["bPre"];  //value
        document.getElementById("timeOn4").value = myObj["mTon"];  
        document.getElementById("timeOff5").value = myObj["mToff"];  
        document.getElementById("bTon1").value = myObj["mTon"]; 
		document.getElementById("bT1_1").value = myObj["bT1"]; 
		document.getElementById("bT1_2").value = myObj["bT1"]; 
        document.getElementById("bT2_3").value = myObj["bT2"]; 
        document.getElementById("bT2_4").value = myObj["bT2"]; 
        document.getElementById("bToff2").value = myObj["mToff"]; 
        document.getElementById("bTLux1").value = myObj["bT1Lux"]; 
        document.getElementById("bTLux2").value = myObj["bT2Lux"]; 
        document.getElementById("bTLux3").value = myObj["bT3Lux"]; 
		document.getElementById("bTTon6").value = myObj["mTon"]; 
		document.getElementById("bT1_5").value = myObj["bT1"]; 
		document.getElementById("bT1_6").value = myObj["bT1"]; 
        document.getElementById("bT2_7").value = myObj["bT2"]; 
        document.getElementById("bT2_8").value = myObj["bT2"]; 
        document.getElementById("bTToff7").value = myObj["mToff"]; 
        document.getElementById("bTLux4").value = myObj["bT1Lux"]; 
        document.getElementById("bTLux5").value = myObj["bT2Lux"]; 
        document.getElementById("bTLux6").value = myObj["bT3Lux"]; 
		document.getElementById("email").value = myObj["email"];

	    hideAllModes();
        hideAllLum();

        if (myObj["mode"]=="manual"){
            document.getElementById("card1").style.display = "block";
			document.getElementById("selectMode").value = "Manual";

        }
        if (myObj["mode"]=="lumAmb"){
            document.getElementById("card2").style.display = "block";
			document.getElementById("selectMode").value = "Por luminosidad amb.";
			document.getElementById("selectLumDiv").style.display = "block";
			if (myObj["lum"]=="manual"){
				document.getElementById("cardL1").style.display = "block";
				document.getElementById("selectLum").value = "Manual";
			}else if (myObj["lum"]=="time"){
				document.getElementById("cardL2").style.display = "block";
				document.getElementById("selectLum").value = "Franja Horaria";
			}
        }
        if (myObj["mode"]=="time"){
            document.getElementById("card3").style.display = "block";
			document.getElementById("selectMode").value = "Temporizado";
			document.getElementById("selectLumDiv").style.display = "block";
			if (myObj["lum"]=="manual"){
				document.getElementById("cardL3").style.display = "block";
				document.getElementById("selectLum").value = "Manual";
			}else if (myObj["lum"]=="time"){
				document.getElementById("cardL4").style.display = "block";
				document.getElementById("selectLum").value = "Franja Horaria";
			}
        }
    }
}


//------------------------------------------
//           Section information
//------------------------------------------


function createTbody(){
	
	var tbody = document.getElementById("tbody");
	for (var i = 0; i < 1; i++) {  // rows
    var row = document.createElement("tr");
		for (var j = 0; j < 7; j++) {
		  var cell = document.createElement("td");
		  var textCell = document.createTextNode("-");
		  cell.appendChild(textCell);
		  row.appendChild(cell); 
		}
    tbody.appendChild(row);
	}
}


function createRow(event){
    var $tbody = document.getElementById("tbody");
    var myObj = JSON.parse(event.data); 
    var node = myObj['node'];
	
	console.log("createRow");
    //document.getElementById("tbody").deleteRow(0);
    const $tr = document.createElement("tr");
    let $tdNodo = document.createElement("td");
	$tdNodo.setAttribute("id", "node"+node);
    $tdNodo.textContent = myObj['node']; // el textContent del td es el nombre
    $tr.appendChild($tdNodo);
        //
    let $tdLuxes = document.createElement("td");
	$tdLuxes.setAttribute("id", "lux"+node);
    $tdLuxes.textContent = myObj['lux']; // el textContent del td es el nombre
    $tr.appendChild($tdLuxes);
        //
    let $tdCurrent = document.createElement("td");
    $tdCurrent.textContent = myObj['I']; // el textContent del td es el nombre
	$tdCurrent.setAttribute("id", "I"+node);
    $tr.appendChild($tdCurrent);
        //
    let $tdPir = document.createElement("td");
	$tdPir.setAttribute("id", "pir"+node);
    $tdPir.textContent = myObj['pir']; // el textContent del td es el nombre
    $tr.appendChild($tdPir);
    //
    let $tdOnOff = document.createElement("td");
	$tdOnOff.setAttribute("id", "onoff"+node);
    $tdOnOff.textContent = myObj['onOff']; // el textContent del td es el nombre
    $tr.appendChild($tdOnOff);
    //
    let $tdBright = document.createElement("td");
	$tdBright.setAttribute("id", "bright"+node);
    $tdBright.textContent = myObj['bright']; // el textContent del td es el nombre
    $tr.appendChild($tdBright);
    //
    let $tdFail = document.createElement("td");
	$tdFail.setAttribute("id", "fail"+node);
    $tdFail.textContent = myObj['fail']; // el textContent del td es el nombre
    $tr.appendChild($tdFail);
    //<tr> to table body
    $tbody.appendChild($tr);   
}

function updateRow(event){
    var $tbody = document.getElementById("tbody");
    var myObj = JSON.parse(event.data); 
    var node = myObj['node'];
	
	console.log("updateRow");
	document.getElementById("node"+node).innerHTML = myObj['node'];
	document.getElementById("lux"+node).innerHTML = myObj['lux'];	
	document.getElementById("I"+node).innerHTML = myObj['I'];
	document.getElementById("pir"+node).innerHTML = myObj['pir'];
	document.getElementById("onoff"+node).innerHTML = myObj['onOff'];
	document.getElementById("bright"+node).innerHTML = myObj['bright'];
	document.getElementById("fail"+node).innerHTML = myObj['fail'];
  
}

function updateInfoTable(event){
	var tbody = document.getElementById("tbody");
	myObj = JSON.parse(event.data);   
	const tableReg = document.getElementById('tbody');
	const searchNode = myObj['node'];
	
	console.log("numrows: "+tableReg.rows.length);
	let found = false;
	let i = 0;
	//for (let i = 0; i < tableReg.rows.length; i++) {
	while (( i < tableReg.rows.length) && !found) {
		const cellsOfRow = tableReg.rows[i].getElementsByTagName('td');
		const compareWith = cellsOfRow[0].innerHTML.toLowerCase();
		
		console.log("comparewith: "+compareWith);
		if (compareWith =="-"){
			document.getElementById("tbody").deleteRow(0);
		}
		console.log("compareWith.indexOf(searchNode): "+compareWith.indexOf(searchNode));
		console.log("found: "+found);
		if (compareWith.indexOf(searchNode) > -1 && !found) {
			console.log("encontrado");
			found = true;
		}
	i++;
	}
	if (found) {
		console.log("found");
		updateRow(event);
	} else {
		createRow(event);
		console.log("not found");
	}
}
 

// -----------------------------------------
//    Section configuration and control
//------------------------------------------

function hideAllModes(){
    for (var i = 0; i < 3; i++){
        document.getElementById("card"+ (i+1)).style.display = "none";
    }
}

function hideAllLum(){
    for (var i = 0; i < 4; i++){
        document.getElementById("cardL"+ (i+1)).style.display = "none";
    }
}

function hideShow() {
    hideAllModes();
    hideAllLum();
    document.getElementById("selectLumDiv").style.display = "none";
    var select = document.getElementById('selectMode');
    select.addEventListener('change',
    function(){
        var selectedOption = this.options[select.selectedIndex];
        hideAllModes();
		document.getElementById("selectLum").value = "";
		if (select.selectedIndex == 1){
	        document.getElementById("card"+select.selectedIndex).style.display = "block";
			document.getElementById("selectLumDiv").style.display = "none";
		}else{document.getElementById("selectLumDiv").style.display = "block";}
	});

    var select2 = document.getElementById('selectLum');
    select2.addEventListener('change',
    function(){
        var selectedOption2 = this.options[select2.selectedIndex];
        hideAllLum();
        document.getElementById("card"+select.selectedIndex).style.display = "block";
		if (select.selectedIndex == 2){
			if (select2.selectedIndex == 1){
				document.getElementById("cardL1").style.display = "block";
			}else{
				document.getElementById("cardL2").style.display = "block";
			}
		}
		if (select.selectedIndex == 3){
			if (select2.selectedIndex == 1){
				document.getElementById("cardL3").style.display = "block";
			}else{
				document.getElementById("cardL4").style.display = "block";
			}
		}
    });
  }


  

function powerOn(){
    document.getElementById("statusOnOff").innerHTML="on"
    sendpValues();
  }

function powerOff(){
    document.getElementById("statusOnOff").innerHTML="off"
    sendpValues();
  }


function sendpValues(){
    var modeCard;
    var brightCard;
    for (var i = 0; i < 3; i++){
        if (document.getElementById("card"+ (i+1)).style.display == "block"){
            modeCard = document.getElementById("card"+ (i+1)).id;    
        }
    }
    
    if(modeCard =="card2" || modeCard == "card3"){
        for (var i = 0; i < 4; i++){
            if (document.getElementById("cardL"+ (i+1)).style.display == "block"){
                brightCard = document.getElementById("cardL"+ (i+1)).id;
            }
        }
    }
	
    var modeName ="";
    var bName = "";
    if (modeCard == "card1"){
        modeName = "manual";
    }
    if (modeCard == "card2"){
        modeName = "lumAmb";
    }
    if (modeCard == "card3"){
        modeName = "time";
    }
    
    if (brightCard == "cardL1" || brightCard == "cardL3" ){
        bName = "manual";
    } else   if (brightCard == "cardL2" || brightCard == "cardL4"){
        bName = "time";
    }

  var msg = {
     type: "pValues",
     mode: modeName,
     mOn: document.getElementById("statusOnOff").innerHTML,
     mLux: document.getElementById("sliderValue3").innerHTML,
     mTon: document.getElementById("timeOn4").value,
     mToff: document.getElementById("timeOff5").value,
     lum: bName,
     bVal: document.getElementById("sliderValue1").innerHTML,
     bT1: document.getElementById("bT1_2").value,
     bT2: document.getElementById("bT2_4").value,
     bT1Lux: document.getElementById("bTLux1").value,
     bT2Lux: document.getElementById("bTLux2").value,
     bT3Lux: document.getElementById("bTLux3").value,
     bPre: document.getElementById("sliderValue2").innerHTML,
	 email: document.getElementById("email").value
    };
    websocket.send(JSON.stringify(msg));
}

function saveEmail(){
    sendpValues();
    alert("¡Cuenta de correo almacenada!");
}



function gotoConfigMode(){
    var msg = {
        type: "gotoConfig"
       };
    websocket.send(JSON.stringify(msg));
    alert("Conectese a la red Wifi: LUCES_CONFIG");
  }
// -----------------------------------------
//                Section Log
//------------------------------------------

function clearLog(){
    var msg = {
        type: "clearLog"
       };
    websocket.send(JSON.stringify(msg));
    alert("¡Registro borrado!");
  }
  
  function DownloadFile(fileName) {
    //Set the File URL.
    var url = "/" + fileName;
  
    //Create XMLHTTP Request.
    var req = new XMLHttpRequest();
    req.open("GET", url, true);
    req.responseType = "blob";
    req.onload = function () {
        //Convert the Byte Data to BLOB object.
        var blob = new Blob([req.response], { type: "application/octetstream" });
  
        //Check the Browser type and download the File.
        var isIE = false || !!document.documentMode;
        if (isIE) {
            window.navigator.msSaveBlob(blob, fileName);
        } else {
            var url = window.URL || window.webkitURL;
            link = url.createObjectURL(blob);
            var a = document.createElement("a");
            a.setAttribute("download", fileName);
            a.setAttribute("href", link);
            document.body.appendChild(a);
            a.click();
            document.body.removeChild(a);
        }
    };
    req.send();
  };
  
  function refreshIframe() {
    var ifr = document.getElementsByName('log')[0];
    ifr.src = ifr.src;
  }
  