(function($){
$.address=(function(){
var _1=function(_2){
$($.address).trigger($.extend($.Event(_2),(function(){
var _3={},_4=$.address.parameterNames();
for(var i=0,l=_4.length;i<l;i++){
_3[_4[i]]=$.address.parameter(_4[i]);
}
return {value:$.address.value(),path:$.address.path(),pathNames:$.address.pathNames(),parameterNames:_4,parameters:_3,queryString:$.address.queryString()};
}).call($.address)));
},_5=function(_6,_7,fn){
$($.address).bind(_6,_7,fn);
return $.address;
},_8=function(){
return (_9.pushState&&_a.state!==_b);
},_c=function(){
return ("/"+_d.pathname.replace(new RegExp(_a.state),"")+_d.search+(_e()?"#"+_e():"")).replace(_f,"/");
},_e=function(){
var _10=_d.href.indexOf("#");
return _10!=-1?_11(_d.href.substr(_10+1),_12):"";
},_13=function(){
return _8()?_c():_e();
},_14=function(){
try{
return top.document!==_b?top:window;
}
catch(e){
return window;
}
},_15=function(){
return "javascript";
},_16=function(_17){
_17=_17.toString();
return (_a.strict&&_17.substr(0,1)!="/"?"/":"")+_17;
},_11=function(_18,_19){
if(_a.crawlable&&_19){
return (_18!==""?"!":"")+_18;
}
return _18.replace(/^\!/,"");
},_1a=function(el,_1b){
return parseInt(el.css(_1b),10);
},_1c=function(el){
var url,s;
for(var i=0,l=el.childNodes.length;i<l;i++){
try{
if(el.childNodes[i].src){
url=String(el.childNodes[i].src);
}
}
catch(e){
}
s=_1c(el.childNodes[i]);
if(s){
url=s;
}
}
return url;
},_1d=function(){
if(!_1e){
var _1f=_13(),_20=_21!=_1f;
if(_20){
if(_22&&_23<7){
_d.reload();
}else{
if(_22&&_23<8&&_a.history){
_24(_25,50);
}
_21=_1f;
_26(_12);
}
}
}
},_26=function(_27){
_1(_28);
_1(_27?_29:_2a);
_24(_2b,10);
},_2b=function(){
if(_a.tracker!=="null"&&_a.tracker!==null){
var fn=$.isFunction(_a.tracker)?_a.tracker:_2c[_a.tracker],_2d=(_d.pathname+_d.search+($.address&&!_8()?$.address.value():"")).replace(/\/\//,"/").replace(/^\/$/,"");
if($.isFunction(fn)){
fn(_2d);
}else{
if($.isFunction(_2c.urchinTracker)){
_2c.urchinTracker(_2d);
}else{
if(_2c.pageTracker!==_b&&$.isFunction(_2c.pageTracker._trackPageview)){
_2c.pageTracker._trackPageview(_2d);
}else{
if(_2c._gaq!==_b&&$.isFunction(_2c._gaq.push)){
_2c._gaq.push(["_trackPageview",decodeURI(_2d)]);
}
}
}
}
}
},_25=function(){
var src=_15()+":"+_12+";document.open();document.writeln('<html><head><title>"+_2e.title.replace("'","\\'")+"</title><script>var "+ID+" = \""+encodeURIComponent(_13())+(_2e.domain!=_d.hostname?"\";document.domain=\""+_2e.domain:"")+"\";</"+"script></head></html>');document.close();";
if(_23<7){
_2f.src=src;
}else{
_2f.contentWindow.location.replace(src);
}
},_30=function(){
if(_31&&_32!=-1){
var _33,_34=_31.substr(_32+1).split("&");
for(i=0;i<_34.length;i++){
_33=_34[i].split("=");
if(/^(autoUpdate|crawlable|history|strict|wrap)$/.test(_33[0])){
_a[_33[0]]=(isNaN(_33[1])?/^(true|yes)$/i.test(_33[1]):(parseInt(_33[1],10)!==0));
}
if(/^(state|tracker)$/.test(_33[0])){
_a[_33[0]]=_33[1];
}
}
_31=null;
}
_21=_13();
},_35=function(){
if(!_36){
_36=_37;
_30();
var _38=function(){
_3e.call(this);
_45.call(this);
},_39=$("body").ajaxComplete(_38);
_38();
if(_a.wrap){
var _3a=$("body > *").wrapAll("<div style=\"padding:"+(_1a(_39,"marginTop")+_1a(_39,"paddingTop"))+"px "+(_1a(_39,"marginRight")+_1a(_39,"paddingRight"))+"px "+(_1a(_39,"marginBottom")+_1a(_39,"paddingBottom"))+"px "+(_1a(_39,"marginLeft")+_1a(_39,"paddingLeft"))+"px;\" />").parent().wrap("<div id=\""+ID+"\" style=\"height:100%;overflow:auto;position:relative;"+(_4e&&!window.statusbar.visible?"resize:both;":"")+"\" />");
$("html, body").css({height:"100%",margin:0,padding:0,overflow:"hidden"});
if(_4e){
$("<style type=\"text/css\" />").appendTo("head").text("#"+ID+"::-webkit-resizer { background-color: #fff; }");
}
}
if(_22&&_23<8){
var _3b=_2e.getElementsByTagName("frameset")[0];
_2f=_2e.createElement((_3b?"":"i")+"frame");
if(_3b){
_3b.insertAdjacentElement("beforeEnd",_2f);
_3b[_3b.cols?"cols":"rows"]+=",0";
_2f.noResize=_37;
_2f.frameBorder=_2f.frameSpacing=0;
}else{
_2f.style.display="none";
_2f.style.width=_2f.style.height=0;
_2f.tabIndex=-1;
_2e.body.insertAdjacentElement("afterBegin",_2f);
}
_24(function(){
$(_2f).bind("load",function(){
var win=_2f.contentWindow;
_21=win[ID]!==_b?decodeURIComponent(win[ID]):"";
if(_21!=_13()){
_26(_12);
_d.hash=_11(_21,_37);
}
});
if(_2f.contentWindow[ID]===_b){
_25();
}
},50);
}
_24(function(){
_1("init");
_26(_12);
},1);
if(!_8()){
if((_22&&_23>7)||(!_22&&("on"+_3c) in _2c)){
if(_2c.addEventListener){
_2c.addEventListener(_3c,_1d,_12);
}else{
if(_2c.attachEvent){
_2c.attachEvent("on"+_3c,_1d);
}
}
}else{
_3d(_1d,50);
}
}
}
},_3e=function(){
var el,_3f=$("a"),_40=_3f.size(),_41=1,_42=-1;
_24(function(){
if(++_42!=_40){
el=$(_3f.get(_42));
if(el.is("[rel*=\"address:\"]")){
el.address();
}
_24(arguments.callee,_41);
}
},_41);
},_43=function(){
if(_21!=_13()){
_21=_13();
_26(_12);
}
},_44=function(){
if(_2c.removeEventListener){
_2c.removeEventListener(_3c,_1d,_12);
}else{
if(_2c.detachEvent){
_2c.detachEvent("on"+_3c,_1d);
}
}
},_45=function(){
if(_a.crawlable){
var _46=_d.pathname.replace(/\/$/,""),_47="_escaped_fragment_";
if($("body").html().indexOf(_47)!=-1){
$("a[href]:not([href^=http]), a[href*=\""+document.domain+"\"]").each(function(){
var _48=$(this).attr("href").replace(/^http:/,"").replace(new RegExp(_46+"/?$"),"");
if(_48===""||_48.indexOf(_47)!=-1){
$(this).attr("href","#"+_48.replace(new RegExp("/(.*)\\?"+_47+"=(.*)$"),"!$2"));
}
});
}
}
},_b,ID="jQueryAddress",_49="string",_3c="hashchange",_4a="init",_28="change",_29="internalChange",_2a="externalChange",_37=true,_12=false,_a={autoUpdate:_37,crawlable:_12,history:_37,strict:_37,wrap:_12},_4b=$.browser,_23=parseFloat($.browser.version),_4c=_4b.mozilla,_22=_4b.msie,_4d=_4b.opera,_4e=_4b.webkit||_4b.safari,_4f=_12,_2c=_14(),_2e=_2c.document,_9=_2c.history,_d=_2c.location,_3d=setInterval,_24=setTimeout,_f=/\/{2,9}/g,_50=navigator.userAgent,_2f,_51,_31=_1c(document),_32=_31?_31.indexOf("?"):-1,_52=_2e.title,_1e=_12,_36=_12,_53=_37,_54=_37,_55=_12,_56={},_21=_13();
if(_22){
_23=parseFloat(_50.substr(_50.indexOf("MSIE")+4));
if(_2e.documentMode&&_2e.documentMode!=_23){
_23=_2e.documentMode!=8?7:8;
}
$(document).bind("propertychange",function(){
if(_2e.title!=_52&&_2e.title.indexOf("#"+_13())!=-1){
_2e.title=_52;
}
});
}
_4f=(_4c&&_23>=1)||(_22&&_23>=6)||(_4d&&_23>=9.5)||(_4e&&_23>=523);
if(_4f){
if(_4d){
history.navigationMode="compatible";
}
if(document.readyState=="complete"){
var _57=setInterval(function(){
if($.address){
_35();
clearInterval(_57);
}
},50);
}else{
_30();
$(_35);
}
var _58=_c();
if(_a.state!==_b){
if(_9.pushState){
if(_58.substr(0,3)=="/#/"){
_d.replace(_a.state.replace(/^\/$/,"")+_58.substr(2));
}
}else{
if(_58!="/"&&_58.replace(/^\/#/,"")!=_e()){
_d.replace(_a.state.replace(/^\/$/,"")+"/#"+_58);
}
}
}
$(window).bind({"popstate":_43,"unload":_44});
}else{
if(!_4f&&_e()!==""){
_d.replace(_d.href.substr(0,_d.href.indexOf("#")));
}else{
_2b();
}
}
return {bind:function(_59,_5a,fn){
return _5(_59,_5a,fn);
},init:function(fn){
return _5(_4a,fn);
},change:function(fn){
return _5(_28,fn);
},internalChange:function(fn){
return _5(_29,fn);
},externalChange:function(fn){
return _5(_2a,fn);
},baseURL:function(){
var url=_d.href;
if(url.indexOf("#")!=-1){
url=url.substr(0,url.indexOf("#"));
}
if(/\/$/.test(url)){
url=url.substr(0,url.length-1);
}
return url;
},autoUpdate:function(_5b){
if(_5b!==_b){
_a.autoUpdate=_5b;
return this;
}
return _a.autoUpdate;
},crawlable:function(_5c){
if(_5c!==_b){
_a.crawlable=_5c;
return this;
}
return _a.crawlable;
},history:function(_5d){
if(_5d!==_b){
_a.history=_5d;
return this;
}
return _a.history;
},state:function(_5e){
if(_5e!==_b){
_a.state=_5e;
return this;
}
return _a.state;
},strict:function(_5f){
if(_5f!==_b){
_a.strict=_5f;
return this;
}
return _a.strict;
},tracker:function(_60){
if(_60!==_b){
_a.tracker=_60;
return this;
}
return _a.tracker;
},wrap:function(_61){
if(_61!==_b){
_a.wrap=_61;
return this;
}
return _a.wrap;
},update:function(){
_55=_37;
this.value(_21);
_55=_12;
return this;
},title:function(_62){
if(_62!==_b){
_24(function(){
_52=_2e.title=_62;
if(_54&&_2f&&_2f.contentWindow&&_2f.contentWindow.document){
_2f.contentWindow.document.title=_62;
_54=_12;
}
if(!_53&&_4c){
_d.replace(_d.href.indexOf("#")!=-1?_d.href:_d.href+"#");
}
_53=_12;
},50);
return this;
}
return _2e.title;
},value:function(_63){
if(_63!==_b){
_63=_16(_63);
if(_63=="/"){
_63="";
}
if(_21==_63&&!_55){
return;
}
_53=_37;
_21=_63;
if(_a.autoUpdate||_55){
_26(_37);
if(_8()){
_9[_a.history?"pushState":"replaceState"]({},"",_a.state.replace(/\/$/,"")+(_21===""?"/":_21));
}else{
_1e=_37;
if(_4e){
if(_a.history){
_d.hash="#"+_11(_21,_37);
}else{
_d.replace("#"+_11(_21,_37));
}
}else{
if(_21!=_13()){
if(_a.history){
_d.hash="#"+_11(_21,_37);
}else{
_d.replace("#"+_11(_21,_37));
}
}
}
if((_22&&_23<8)&&_a.history){
_24(_25,50);
}
if(_4e){
_24(function(){
_1e=_12;
},1);
}else{
_1e=_12;
}
}
}
return this;
}
if(!_4f){
return null;
}
return _16(_21);
},path:function(_64){
if(_64!==_b){
var qs=this.queryString(),_65=this.hash();
this.value(_64+(qs?"?"+qs:"")+(_65?"#"+_65:""));
return this;
}
return _16(_21).split("#")[0].split("?")[0];
},pathNames:function(){
var _66=this.path(),_67=_66.replace(_f,"/").split("/");
if(_66.substr(0,1)=="/"||_66.length===0){
_67.splice(0,1);
}
if(_66.substr(_66.length-1,1)=="/"){
_67.splice(_67.length-1,1);
}
return _67;
},queryString:function(_68){
if(_68!==_b){
var _69=this.hash();
this.value(this.path()+(_68?"?"+_68:"")+(_69?"#"+_69:""));
return this;
}
var arr=_21.split("?");
return arr.slice(1,arr.length).join("?").split("#")[0];
},parameter:function(_6a,_6b,_6c){
var i,_6d;
if(_6b!==_b){
var _6e=this.parameterNames();
_6d=[];
_6b=_6b?_6b.toString():"";
for(i=0;i<_6e.length;i++){
var n=_6e[i],v=this.parameter(n);
if(typeof v==_49){
v=[v];
}
if(n==_6a){
v=(_6b===null||_6b==="")?[]:(_6c?v.concat([_6b]):[_6b]);
}
for(var j=0;j<v.length;j++){
_6d.push(n+"="+v[j]);
}
}
if($.inArray(_6a,_6e)==-1&&_6b!==null&&_6b!==""){
_6d.push(_6a+"="+_6b);
}
this.queryString(_6d.join("&"));
return this;
}
_6b=this.queryString();
if(_6b){
var r=[];
_6d=_6b.split("&");
for(i=0;i<_6d.length;i++){
var p=_6d[i].split("=");
if(p[0]==_6a){
r.push(p.slice(1).join("="));
}
}
if(r.length!==0){
return r.length!=1?r:r[0];
}
}
},parameterNames:function(){
var qs=this.queryString(),_6f=[];
if(qs&&qs.indexOf("=")!=-1){
var _70=qs.split("&");
for(var i=0;i<_70.length;i++){
var _71=_70[i].split("=")[0];
if($.inArray(_71,_6f)==-1){
_6f.push(_71);
}
}
}
return _6f;
},hash:function(_72){
if(_72!==_b){
this.value(_21.split("#")[0]+(_72?"#"+_72:""));
return this;
}
var arr=_21.split("#");
return arr.slice(1,arr.length).join("#");
}};
})();
$.fn.address=function(fn){
if(!$(this).attr("address")){
var f=function(e){
if(e.shiftKey||e.ctrlKey||e.metaKey){
return true;
}
if($(this).is("a")){
var _73=fn?fn.call(this):/address:/.test($(this).attr("rel"))?$(this).attr("rel").split("address:")[1].split(" ")[0]:$.address.state()!==undefined&&$.address.state()!="/"?$(this).attr("href").replace(new RegExp("^(.*"+$.address.state()+"|\\.)"),""):$(this).attr("href").replace(/^(#\!?|\.)/,"");
$.address.value(_73);
e.preventDefault();
}
};
$(this).click(f).live("click",f).live("submit",function(e){
if($(this).is("form")){
var _74=$(this).attr("action"),_75=fn?fn.call(this):(_74.indexOf("?")!=-1?_74.replace(/&$/,""):_74+"?")+$(this).serialize();
$.address.value(_75);
e.preventDefault();
}
}).attr("address",true);
}
return this;
};
})(jQuery);

