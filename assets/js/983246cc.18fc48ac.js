"use strict";(self.webpackChunkxtd=self.webpackChunkxtd||[]).push([[4800],{91971:(e,t,n)=>{n.d(t,{Zo:()=>u,kt:()=>g});var r=n(76687);function o(e,t,n){return t in e?Object.defineProperty(e,t,{value:n,enumerable:!0,configurable:!0,writable:!0}):e[t]=n,e}function a(e,t){var n=Object.keys(e);if(Object.getOwnPropertySymbols){var r=Object.getOwnPropertySymbols(e);t&&(r=r.filter((function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable}))),n.push.apply(n,r)}return n}function i(e){for(var t=1;t<arguments.length;t++){var n=null!=arguments[t]?arguments[t]:{};t%2?a(Object(n),!0).forEach((function(t){o(e,t,n[t])})):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(n)):a(Object(n)).forEach((function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(n,t))}))}return e}function s(e,t){if(null==e)return{};var n,r,o=function(e,t){if(null==e)return{};var n,r,o={},a=Object.keys(e);for(r=0;r<a.length;r++)n=a[r],t.indexOf(n)>=0||(o[n]=e[n]);return o}(e,t);if(Object.getOwnPropertySymbols){var a=Object.getOwnPropertySymbols(e);for(r=0;r<a.length;r++)n=a[r],t.indexOf(n)>=0||Object.prototype.propertyIsEnumerable.call(e,n)&&(o[n]=e[n])}return o}var l=r.createContext({}),c=function(e){var t=r.useContext(l),n=t;return e&&(n="function"==typeof e?e(t):i(i({},t),e)),n},u=function(e){var t=c(e.components);return r.createElement(l.Provider,{value:t},e.children)},p="mdxType",d={inlineCode:"code",wrapper:function(e){var t=e.children;return r.createElement(r.Fragment,{},t)}},m=r.forwardRef((function(e,t){var n=e.components,o=e.mdxType,a=e.originalType,l=e.parentName,u=s(e,["components","mdxType","originalType","parentName"]),p=c(n),m=o,g=p["".concat(l,".").concat(m)]||p[m]||d[m]||a;return n?r.createElement(g,i(i({ref:t},u),{},{components:n})):r.createElement(g,i({ref:t},u))}));function g(e,t){var n=arguments,o=t&&t.mdxType;if("string"==typeof e||o){var a=n.length,i=new Array(a);i[0]=m;var s={};for(var l in t)hasOwnProperty.call(t,l)&&(s[l]=t[l]);s.originalType=e,s[p]="string"==typeof e?e:o,i[1]=s;for(var c=2;c<a;c++)i[c]=n[c];return r.createElement.apply(null,i)}return r.createElement.apply(null,n)}m.displayName="MDXCreateElement"},80091:(e,t,n)=>{n.r(t),n.d(t,{assets:()=>l,contentTitle:()=>i,default:()=>d,frontMatter:()=>a,metadata:()=>s,toc:()=>c});var r=n(855),o=(n(76687),n(91971));const a={},i="Proxy",s={unversionedId:"documentation/Design Guidelines/Common Design Patterns/proxy",id:"documentation/Design Guidelines/Common Design Patterns/proxy",title:"Proxy",description:"The Proxy design pattern provides a surrogate or placeholder for another object to control access to it.",source:"@site/docs/documentation/Design Guidelines/Common Design Patterns/proxy.md",sourceDirName:"documentation/Design Guidelines/Common Design Patterns",slug:"/documentation/Design Guidelines/Common Design Patterns/proxy",permalink:"/xtd/docs/documentation/Design Guidelines/Common Design Patterns/proxy",draft:!1,tags:[],version:"current",frontMatter:{},sidebar:"tutorialSidebar",previous:{title:"Builder",permalink:"/xtd/docs/documentation/Design Guidelines/Common Design Patterns/prototype"},next:{title:"Singleton",permalink:"/xtd/docs/documentation/Design Guidelines/Common Design Patterns/singleton"}},l={},c=[{value:"UML class diagram",id:"uml-class-diagram",level:2},{value:"Sample code",id:"sample-code",level:2},{value:"Output",id:"output",level:2},{value:"See also",id:"see-also",level:2}],u={toc:c},p="wrapper";function d(e){let{components:t,...a}=e;return(0,o.kt)(p,(0,r.Z)({},u,a,{components:t,mdxType:"MDXLayout"}),(0,o.kt)("h1",{id:"proxy"},"Proxy"),(0,o.kt)("p",null,"The Proxy design pattern provides a surrogate or placeholder for another object to control access to it."),(0,o.kt)("p",null,"Usage\xa0\xa0\xa0\xa0\xa0",(0,o.kt)("img",{alt:"Usage",src:n(24248).Z,width:"101",height:"20"}),"\xa0\xa0\xa0\xa0\xa0Medium-high"),(0,o.kt)("h2",{id:"uml-class-diagram"},"UML class diagram"),(0,o.kt)("p",null,"A visualization of the classes and objects participating in this pattern."),(0,o.kt)("p",null,(0,o.kt)("img",{alt:"diagram",src:n(18413).Z,width:"405",height:"252"})),(0,o.kt)("h2",{id:"sample-code"},"Sample code"),(0,o.kt)("p",null,"This structural code demonstrates the Proxy pattern which provides a representative object (proxy) that controls access to another similar object."),(0,o.kt)("pre",null,(0,o.kt)("code",{parentName:"pre",className:"language-cpp"},"")),(0,o.kt)("h2",{id:"output"},"Output"),(0,o.kt)("pre",null,(0,o.kt)("code",{parentName:"pre"},"")),(0,o.kt)("h2",{id:"see-also"},"See also"),(0,o.kt)("p",null,"\u200b"),(0,o.kt)("ul",null,(0,o.kt)("li",{parentName:"ul"},(0,o.kt)("a",{parentName:"li",href:"/docs/documentation/Design%20Guidelines/Common%20Design%20Patterns"},"Common Design Patterns")),(0,o.kt)("li",{parentName:"ul"},(0,o.kt)("a",{parentName:"li",href:"/docs/documentation/Design%20Guidelines"},"Design Guidelines")),(0,o.kt)("li",{parentName:"ul"},(0,o.kt)("a",{parentName:"li",href:"/docs/documentation"},"Documentation"))))}d.isMDXComponent=!0},18413:(e,t,n)=>{n.d(t,{Z:()=>r});const r=n.p+"assets/images/proxy-e9e8e687fbb250683b4fd0c9d9562092.png"},24248:(e,t,n)=>{n.d(t,{Z:()=>r});const r="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGUAAAAUCAYAAACUAvOrAAAABmJLR0QA/wD/AP+gvaeTAAAACXBIWXMAAAsTAAALEwEAmpwYAAAAB3RJTUUH4wEfEgc1b06IDwAAABl0RVh0Q29tbWVudABDcmVhdGVkIHdpdGggR0lNUFeBDhcAAACxSURBVFjD7ZdBDoAgDAS7hIf5NJ7mz+rJxHhC2JoqO2cdoNhthLubyEV98jAAd3cwFgbgZmZs36wz4oxXetx1ZgHGwRlFuDtYhWV4Rt4vkfI3XBG+T8UXG2ZUMCPxmgqzexyJVTwZ9Oy8jfrCM8XXiK/8qUOyMbqvmmHDjGHK9DFnXXh8iXcoKkHC2DMztYo6RfQP+q1xjHtb0tfavO90qFMUX0KXoksRuhT9pwh1yuIcZx6IHz4dkvkAAAAASUVORK5CYII="}}]);