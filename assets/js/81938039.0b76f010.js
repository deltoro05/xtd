"use strict";(self.webpackChunkxtd=self.webpackChunkxtd||[]).push([[7350],{91971:(e,t,n)=>{n.d(t,{Zo:()=>c,kt:()=>g});var r=n(76687);function a(e,t,n){return t in e?Object.defineProperty(e,t,{value:n,enumerable:!0,configurable:!0,writable:!0}):e[t]=n,e}function i(e,t){var n=Object.keys(e);if(Object.getOwnPropertySymbols){var r=Object.getOwnPropertySymbols(e);t&&(r=r.filter((function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable}))),n.push.apply(n,r)}return n}function o(e){for(var t=1;t<arguments.length;t++){var n=null!=arguments[t]?arguments[t]:{};t%2?i(Object(n),!0).forEach((function(t){a(e,t,n[t])})):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(n)):i(Object(n)).forEach((function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(n,t))}))}return e}function s(e,t){if(null==e)return{};var n,r,a=function(e,t){if(null==e)return{};var n,r,a={},i=Object.keys(e);for(r=0;r<i.length;r++)n=i[r],t.indexOf(n)>=0||(a[n]=e[n]);return a}(e,t);if(Object.getOwnPropertySymbols){var i=Object.getOwnPropertySymbols(e);for(r=0;r<i.length;r++)n=i[r],t.indexOf(n)>=0||Object.prototype.propertyIsEnumerable.call(e,n)&&(a[n]=e[n])}return a}var l=r.createContext({}),p=function(e){var t=r.useContext(l),n=t;return e&&(n="function"==typeof e?e(t):o(o({},t),e)),n},c=function(e){var t=p(e.components);return r.createElement(l.Provider,{value:t},e.children)},u="mdxType",m={inlineCode:"code",wrapper:function(e){var t=e.children;return r.createElement(r.Fragment,{},t)}},d=r.forwardRef((function(e,t){var n=e.components,a=e.mdxType,i=e.originalType,l=e.parentName,c=s(e,["components","mdxType","originalType","parentName"]),u=p(n),d=a,g=u["".concat(l,".").concat(d)]||u[d]||m[d]||i;return n?r.createElement(g,o(o({ref:t},c),{},{components:n})):r.createElement(g,o({ref:t},c))}));function g(e,t){var n=arguments,a=t&&t.mdxType;if("string"==typeof e||a){var i=n.length,o=new Array(i);o[0]=d;var s={};for(var l in t)hasOwnProperty.call(t,l)&&(s[l]=t[l]);s.originalType=e,s[u]="string"==typeof e?e:a,o[1]=s;for(var p=2;p<i;p++)o[p]=n[p];return r.createElement.apply(null,o)}return r.createElement.apply(null,n)}d.displayName="MDXCreateElement"},48487:(e,t,n)=>{n.r(t),n.d(t,{assets:()=>l,contentTitle:()=>o,default:()=>m,frontMatter:()=>i,metadata:()=>s,toc:()=>p});var r=n(855),a=(n(76687),n(91971));const i={},o="Interpreter",s={unversionedId:"documentation/Design Guidelines/Common Design Patterns/interpreter",id:"documentation/Design Guidelines/Common Design Patterns/interpreter",title:"Interpreter",description:"Given a language, the Interpreter design pattern defines a representation for its grammar along with an interpreter that uses the representation to interpret sentences in the language.",source:"@site/docs/documentation/Design Guidelines/Common Design Patterns/interpreter.md",sourceDirName:"documentation/Design Guidelines/Common Design Patterns",slug:"/documentation/Design Guidelines/Common Design Patterns/interpreter",permalink:"/xtd/docs/documentation/Design Guidelines/Common Design Patterns/interpreter",draft:!1,tags:[],version:"current",frontMatter:{},sidebar:"tutorialSidebar",previous:{title:"Flyweight",permalink:"/xtd/docs/documentation/Design Guidelines/Common Design Patterns/flyweight"},next:{title:"Iterator",permalink:"/xtd/docs/documentation/Design Guidelines/Common Design Patterns/iterator"}},l={},p=[{value:"UML class diagram",id:"uml-class-diagram",level:2},{value:"Sample code",id:"sample-code",level:2},{value:"Output",id:"output",level:2},{value:"See also",id:"see-also",level:2}],c={toc:p},u="wrapper";function m(e){let{components:t,...i}=e;return(0,a.kt)(u,(0,r.Z)({},c,i,{components:t,mdxType:"MDXLayout"}),(0,a.kt)("h1",{id:"interpreter"},"Interpreter"),(0,a.kt)("p",null,"Given a language, the Interpreter design pattern defines a representation for its grammar along with an interpreter that uses the representation to interpret sentences in the language."),(0,a.kt)("p",null,"Usage\xa0\xa0\xa0\xa0\xa0",(0,a.kt)("img",{alt:"Usage",src:n(13868).Z,width:"101",height:"20"}),"\xa0\xa0\xa0\xa0\xa0Low"),(0,a.kt)("h2",{id:"uml-class-diagram"},"UML class diagram"),(0,a.kt)("p",null,"A visualization of the classes and objects participating in this pattern."),(0,a.kt)("p",null,(0,a.kt)("img",{alt:"diagram",src:n(40526).Z,width:"404",height:"266"})),(0,a.kt)("h2",{id:"sample-code"},"Sample code"),(0,a.kt)("p",null,"This structural code demonstrates the Interpreter patterns, which using a defined grammar, provides the interpreter that processes parsed statements."),(0,a.kt)("pre",null,(0,a.kt)("code",{parentName:"pre",className:"language-cpp"},"")),(0,a.kt)("h2",{id:"output"},"Output"),(0,a.kt)("pre",null,(0,a.kt)("code",{parentName:"pre"},"")),(0,a.kt)("h2",{id:"see-also"},"See also"),(0,a.kt)("p",null,"\u200b"),(0,a.kt)("ul",null,(0,a.kt)("li",{parentName:"ul"},(0,a.kt)("a",{parentName:"li",href:"/docs/documentation/Design%20Guidelines/Common%20Design%20Patterns"},"Common Design Patterns")),(0,a.kt)("li",{parentName:"ul"},(0,a.kt)("a",{parentName:"li",href:"/docs/documentation/Design%20Guidelines"},"Design Guidelines")),(0,a.kt)("li",{parentName:"ul"},(0,a.kt)("a",{parentName:"li",href:"/docs/documentation"},"Documentation"))))}m.isMDXComponent=!0},40526:(e,t,n)=>{n.d(t,{Z:()=>r});const r=n.p+"assets/images/interpreter-c1908f24fc0d88fce8be458cdc25253b.png"},13868:(e,t,n)=>{n.d(t,{Z:()=>r});const r="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGUAAAAUCAYAAACUAvOrAAAABmJLR0QA/wD/AP+gvaeTAAAACXBIWXMAAAsTAAALEwEAmpwYAAAAB3RJTUUH4wEfEg8SAp23bAAAABl0RVh0Q29tbWVudABDcmVhdGVkIHdpdGggR0lNUFeBDhcAAAC1SURBVFjD7ZdBDoAgDAS7hIf5NJ7mz+rBmBhPCltSdeesAxS7jXB3E7moTx4G4O4OxsIA3MyM7Rt1RpzxzB13HVmAcXBGEa4OVmEZnp73S6R8hivC96r4YsOMCmYknlNhdI89sYong56dt1FfeKb46vGVL3VINnr3VTNsmDFMmT7mrAuPLzGHohIkjD0zU6uoU8T9Qb80jnHdPa1xfIfnD77DoU5RfAldii5F6FL0nyLUKT9nAzA6ix/x1rtMAAAAAElFTkSuQmCC"}}]);