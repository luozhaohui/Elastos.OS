var bNode = true;

var root = global||window;
root.ElastosTest || (root.ElastosTest = {});

if (bNode) {
    root.elastos = require('./elastos.node');
}

ElastosTest.fnTestCarDataType = function(looptimes) {

var a = [];
var s = "";
var p = 0;

try {
    var sEcoName,sClassName;
    var oLog,oCarObject;

    sEcoName = "/data/elastos/JSTestLog.eco";
    sClassName = "CTestLog";
    oLog = elastos[bNode?'require':'Require'](sEcoName, sClassName);;

    sEcoName = "/data/elastos/JSTestCarDataType.eco";
    sClassName = "CTestCarDataType";

    //Exception Test Cases
    //oCarObject = elastos.require(sEcoName); //Test: wrong number of arguments
    //oCarObject = elastos.require(1, sClassName); //Test: wrong number of parameter : ClassName
    //oCarObject = elastos.require(sEcoName,1); //Test: wrong number of parameter : ClassName
    //sEcoName = "XXX"; //Test: Acquire module info failed!
    //sClassName = "YYY"; //Test: Acquire class info failed!  BUGTOFIX: Segmentation fault!!!

    oCarObject = elastos.require(sEcoName, sClassName);   //Test: Correct form

    function sv() {return this;}
    function sx() {return "0x"+this.toString(16).toUpperCase();}
    function sf() {return sv.call(this) + "====to be shown correctly";}
    function smuid() {return sax.call(this);}
    function sguid() {
        return JSON.stringify({
            clsid:smuid.call(this.clsid),
            mUunm:this.mUunm,
            carcode:sx.call(this.carcode)
        });
    }
    function sav() {return JSON.stringify(this);}
    function sax() {
        var a = [];
        for(var i=0,im=this.length;i<im;i++){
            a.push(((this[i] instanceof Array)?sax:sx).call(this[i]));
        }
        return sav.call(a);
    }
    function saf() {return sav.call(this) + "====to be shown correctly";}
    function samuid() {return sav.call(this) + "====to be shown correctly";}
    function saguid() {return sav.call(this) + "====to be shown correctly";}

    a.push("Test_NULL========" + oCarObject.Test_NULL());

    var aTestData = {
        "Int16":{v:16, va:[1, 2, 3], sv:sv,sa:sav},
        "Int32":{v:32, va:[4, 5, 6], sv:sv,sa:sav},
        "Int64":{v:64, va:[7, 8, 9], sv:sv,sa:sav},
        "Byte":{v:8, va:[10, 11, 12], sv:sv,sa:sav},
        "Float":{v:12.34, va:[12.34, 56.78, 12.78], sv:sf,sa:saf},
        "Double":{v:1234.5678, va:[1234.5678, 2345.6789, 3456.7890], sv:sv,sa:sav},
        "Char":{v:"A", va:['A', 'B', 'C'], sv:sv,sa:sav},
        "String":{v:"HelloWorld", va:['ABC', 'BCD', 'CDE'], sv:sv,sa:sav},
        "Boolean":{v:false, va:[true, false, true], sv:sv,sa:sav},
        "ECode":{v:0xA0010000, va:[0xA0010000, 0xA0010001, 0xA0010002], sv:sx,sa:sax},
        "Enum":{v:0x1, va:[0x1, 0x10, 0x100], sv:sv,sa:sav},
        "EMuid":{
            v:[0x12345678,0x1234,0x5678,[0x12,0x23,0x34,0x45,0x56,0x67,0x78,0x89]],
            va:[
                [0x12345678,0x1234,0x5678,[0x12,0x23,0x34,0x45,0x56,0x67,0x78,0x89]],
                [0x23456789,0x2345,0x6789,[0x23,0x34,0x45,0x56,0x67,0x78,0x89,0x9A]],
                [0x3456789A,0x3456,0x789A,[0x34,0x45,0x56,0x67,0x78,0x89,0x9A,0xAB]]
            ],
            sv:smuid,
            sa:samuid    //to be completed
        },
        "EGuid":{
            v:{
                clsid:[0x12345678,0x1234,0x5678,[0x12,0x23,0x34,0x45,0x56,0x67,0x78,0x89]],
                mUunm:"test-eguid-clsid",
                carcode:0x1234
            },
            va:[
                {
                    clsid:[0x12345678,0x1234,0x5678,[0x12,0x23,0x34,0x45,0x56,0x67,0x78,0x89]],
                    mUunm:"test-eguid-clsid",
                    carcode:0x1234
                },
                {
                    clsid:[0x23456789,0x2345,0x6789,[0x23,0x34,0x45,0x56,0x67,0x78,0x89,0x9A]],
                    mUunm:"test-eguid-clsid",
                    carcode:0x2345
                },
                {
                    clsid:[0x3456789A,0x3456,0x789A,[0x34,0x45,0x56,0x67,0x78,0x89,0x9A,0xAB]],
                    mUunm:"test-eguid-clsid",
                    carcode:0x3456
                }
            ],
            sv:sguid,
            sa:saguid
        },
        "Interface":{v:null,va:[null,null,null],sv:null,sa:null}    //to be completed
    };

    for (var i = 0; i < looptimes; i++) {
        for (var prop in aTestData) {
            if(prop == "Interface") continue;    //comment when completed

            var oProp = aTestData[prop];

            var sFunName = "Test_" + prop;
            a.push(sFunName + "========" + oProp.sv.call(oCarObject[sFunName](oProp.v)));

            if(prop == "EMuid") continue;    //comment when completed
            if(prop == "EGuid") continue;    //comment when completed

            var sFunName = "Test_ArrayOf_" + prop;
            a.push(sFunName + "========" + oProp.sa.call(oCarObject[sFunName](oProp.va)));
        }
    }
} catch(e) {
    a.push("test error at p = " + p + ' : ' + e);
}

if (bNode) {
    s = a.join("\n");
    console.log('elastos.require = ',s);
    oLog.Log('elastos cardatetype test result: '+s);
}
else {
    s = a.join("<br>");
    var oMain = document.getElementById("main");
    oMain && (oMain.innerHTML = s);
}

}    //fnTestCarDataType

ElastosTest.fnTestCarDataType(5);

//---------------------------end--------------------------------
