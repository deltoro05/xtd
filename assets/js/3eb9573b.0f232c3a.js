"use strict";(self.webpackChunkxtd=self.webpackChunkxtd||[]).push([[3807],{91971:(e,t,n)=>{n.d(t,{Zo:()=>m,kt:()=>f});var s=n(76687);function i(e,t,n){return t in e?Object.defineProperty(e,t,{value:n,enumerable:!0,configurable:!0,writable:!0}):e[t]=n,e}function a(e,t){var n=Object.keys(e);if(Object.getOwnPropertySymbols){var s=Object.getOwnPropertySymbols(e);t&&(s=s.filter((function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable}))),n.push.apply(n,s)}return n}function r(e){for(var t=1;t<arguments.length;t++){var n=null!=arguments[t]?arguments[t]:{};t%2?a(Object(n),!0).forEach((function(t){i(e,t,n[t])})):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(n)):a(Object(n)).forEach((function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(n,t))}))}return e}function o(e,t){if(null==e)return{};var n,s,i=function(e,t){if(null==e)return{};var n,s,i={},a=Object.keys(e);for(s=0;s<a.length;s++)n=a[s],t.indexOf(n)>=0||(i[n]=e[n]);return i}(e,t);if(Object.getOwnPropertySymbols){var a=Object.getOwnPropertySymbols(e);for(s=0;s<a.length;s++)n=a[s],t.indexOf(n)>=0||Object.prototype.propertyIsEnumerable.call(e,n)&&(i[n]=e[n])}return i}var l=s.createContext({}),c=function(e){var t=s.useContext(l),n=t;return e&&(n="function"==typeof e?e(t):r(r({},t),e)),n},m=function(e){var t=c(e.components);return s.createElement(l.Provider,{value:t},e.children)},u="mdxType",p={inlineCode:"code",wrapper:function(e){var t=e.children;return s.createElement(s.Fragment,{},t)}},d=s.forwardRef((function(e,t){var n=e.components,i=e.mdxType,a=e.originalType,l=e.parentName,m=o(e,["components","mdxType","originalType","parentName"]),u=c(n),d=i,f=u["".concat(l,".").concat(d)]||u[d]||p[d]||a;return n?s.createElement(f,r(r({ref:t},m),{},{components:n})):s.createElement(f,r({ref:t},m))}));function f(e,t){var n=arguments,i=t&&t.mdxType;if("string"==typeof e||i){var a=n.length,r=new Array(a);r[0]=d;var o={};for(var l in t)hasOwnProperty.call(t,l)&&(o[l]=t[l]);o.originalType=e,o[u]="string"==typeof e?e:i,r[1]=o;for(var c=2;c<a;c++)r[c]=n[c];return s.createElement.apply(null,r)}return s.createElement.apply(null,n)}d.displayName="MDXCreateElement"},32686:(e,t,n)=>{n.r(t),n.d(t,{assets:()=>l,contentTitle:()=>r,default:()=>p,frontMatter:()=>a,metadata:()=>o,toc:()=>c});var s=n(855),i=(n(76687),n(91971));const a={},r="Base Classes for Implementing Abstractions",o={unversionedId:"documentation/Design Guidelines/Designing for Extensibility/base_classes_for_implementing_abstractions",id:"documentation/Design Guidelines/Designing for Extensibility/base_classes_for_implementing_abstractions",title:"Base Classes for Implementing Abstractions",description:"Strictly speaking, a class becomes a base class when another class is derived from it. For the purpose of this section, however, a base class is a class designed mainly to provide a common abstraction or for other classes to reuse some default implementation though inheritance. Base classes usually sit in the middle of inheritance hierarchies, between an abstraction at the root of a hierarchy and several custom implementations at the bottom.",source:"@site/docs/documentation/Design Guidelines/Designing for Extensibility/base_classes_for_implementing_abstractions.md",sourceDirName:"documentation/Design Guidelines/Designing for Extensibility",slug:"/documentation/Design Guidelines/Designing for Extensibility/base_classes_for_implementing_abstractions",permalink:"/xtd/docs/documentation/Design Guidelines/Designing for Extensibility/base_classes_for_implementing_abstractions",draft:!1,tags:[],version:"current",frontMatter:{},sidebar:"tutorialSidebar",previous:{title:"Abstractions (Abstract Types and Interfaces)",permalink:"/xtd/docs/documentation/Design Guidelines/Designing for Extensibility/abstractions_abstract_types_and_interfaces"},next:{title:"Events and Callbacks",permalink:"/xtd/docs/documentation/Design Guidelines/Designing for Extensibility/events_and_callbacks"}},l={},c=[],m={toc:c},u="wrapper";function p(e){let{components:t,...n}=e;return(0,i.kt)(u,(0,s.Z)({},m,n,{components:t,mdxType:"MDXLayout"}),(0,i.kt)("h1",{id:"base-classes-for-implementing-abstractions"},"Base Classes for Implementing Abstractions"),(0,i.kt)("p",null,"Strictly speaking, a class becomes a base class when another class is derived from it. For the purpose of this section, however, a base class is a class designed mainly to provide a common abstraction or for other classes to reuse some default implementation though inheritance. Base classes usually sit in the middle of inheritance hierarchies, between an abstraction at the root of a hierarchy and several custom implementations at the bottom."),(0,i.kt)("p",null,"They serve as implementation helpers for implementing abstractions."),(0,i.kt)("p",null,"Base classes are usually not suited to serve as abstractions by themselves, because they tend to contain too much implementation."),(0,i.kt)("p",null,"As previously discussed, base classes can provide invaluable help for users who need to implement abstractions, but at the same time they can be a significant liability. They add surface area and increase the depth of inheritance hierarchies and so conceptually complicate the framework. Therefore, base classes should be used only if they provide significant value to the users of the framework. They should be avoided if they provide value only to the implementers of the framework, in which case delegation to an internal implementation instead of inheritance from a base class should be strongly considered."),(0,i.kt)("p",null,(0,i.kt)("strong",{parentName:"p"},"\u2714\ufe0f CONSIDER")," making base classes abstract even if they don\u2019t contain any abstract members. This clearly communicates to the users that the class is designed solely to be inherited from."),(0,i.kt)("p",null,(0,i.kt)("strong",{parentName:"p"},"\u2714\ufe0f CONSIDER")," placing base classes in a separate namespace from the mainline scenario types. By definition, base classes are intended for advanced extensibility scenarios and therefore are not interesting to the majority of users."),(0,i.kt)("p",null,(0,i.kt)("strong",{parentName:"p"},"\u274c AVOID"),' naming base classes with a "_base" suffix if the class is intended for use in public APIs.'),(0,i.kt)("h1",{id:"see-also"},"See also"),(0,i.kt)("p",null,"\u200b"),(0,i.kt)("ul",null,(0,i.kt)("li",{parentName:"ul"},(0,i.kt)("a",{parentName:"li",href:"/docs/documentation/Design%20Guidelines/Designing%20for%20Extensibility"},"Design for Extensibility")),(0,i.kt)("li",{parentName:"ul"},(0,i.kt)("a",{parentName:"li",href:"/docs/documentation/Design%20Guidelines"},"Design Guidelines")),(0,i.kt)("li",{parentName:"ul"},(0,i.kt)("a",{parentName:"li",href:"/docs/documentation"},"Documentation"))))}p.isMDXComponent=!0}}]);