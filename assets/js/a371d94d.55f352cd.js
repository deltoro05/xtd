"use strict";(self.webpackChunkxtd=self.webpackChunkxtd||[]).push([[6225],{91971:(e,t,n)=>{n.d(t,{Zo:()=>u,kt:()=>g});var s=n(76687);function i(e,t,n){return t in e?Object.defineProperty(e,t,{value:n,enumerable:!0,configurable:!0,writable:!0}):e[t]=n,e}function r(e,t){var n=Object.keys(e);if(Object.getOwnPropertySymbols){var s=Object.getOwnPropertySymbols(e);t&&(s=s.filter((function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable}))),n.push.apply(n,s)}return n}function a(e){for(var t=1;t<arguments.length;t++){var n=null!=arguments[t]?arguments[t]:{};t%2?r(Object(n),!0).forEach((function(t){i(e,t,n[t])})):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(n)):r(Object(n)).forEach((function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(n,t))}))}return e}function o(e,t){if(null==e)return{};var n,s,i=function(e,t){if(null==e)return{};var n,s,i={},r=Object.keys(e);for(s=0;s<r.length;s++)n=r[s],t.indexOf(n)>=0||(i[n]=e[n]);return i}(e,t);if(Object.getOwnPropertySymbols){var r=Object.getOwnPropertySymbols(e);for(s=0;s<r.length;s++)n=r[s],t.indexOf(n)>=0||Object.prototype.propertyIsEnumerable.call(e,n)&&(i[n]=e[n])}return i}var c=s.createContext({}),l=function(e){var t=s.useContext(c),n=t;return e&&(n="function"==typeof e?e(t):a(a({},t),e)),n},u=function(e){var t=l(e.components);return s.createElement(c.Provider,{value:t},e.children)},d="mdxType",p={inlineCode:"code",wrapper:function(e){var t=e.children;return s.createElement(s.Fragment,{},t)}},m=s.forwardRef((function(e,t){var n=e.components,i=e.mdxType,r=e.originalType,c=e.parentName,u=o(e,["components","mdxType","originalType","parentName"]),d=l(n),m=i,g=d["".concat(c,".").concat(m)]||d[m]||p[m]||r;return n?s.createElement(g,a(a({ref:t},u),{},{components:n})):s.createElement(g,a({ref:t},u))}));function g(e,t){var n=arguments,i=t&&t.mdxType;if("string"==typeof e||i){var r=n.length,a=new Array(r);a[0]=m;var o={};for(var c in t)hasOwnProperty.call(t,c)&&(o[c]=t[c]);o.originalType=e,o[d]="string"==typeof e?e:i,a[1]=o;for(var l=2;l<r;l++)a[l]=n[l];return s.createElement.apply(null,a)}return s.createElement.apply(null,n)}m.displayName="MDXCreateElement"},95768:(e,t,n)=>{n.r(t),n.d(t,{assets:()=>c,contentTitle:()=>a,default:()=>p,frontMatter:()=>r,metadata:()=>o,toc:()=>l});var s=n(855),i=(n(76687),n(91971));const r={},a="Static Class Design",o={unversionedId:"documentation/Design Guidelines/Type Design Guidelines/static_class_design",id:"documentation/Design Guidelines/Type Design Guidelines/static_class_design",title:"Static Class Design",description:"A static class is defined as a class that contains only static members (of course besides the instance members inherited from System.Object and possibly a private constructor). C++ languages do not provide built-in support for static classes.",source:"@site/docs/documentation/Design Guidelines/Type Design Guidelines/static_class_design.md",sourceDirName:"documentation/Design Guidelines/Type Design Guidelines",slug:"/documentation/Design Guidelines/Type Design Guidelines/static_class_design",permalink:"/xtd/docs/documentation/Design Guidelines/Type Design Guidelines/static_class_design",draft:!1,tags:[],version:"current",frontMatter:{},sidebar:"tutorialSidebar",previous:{title:"Nested Types",permalink:"/xtd/docs/documentation/Design Guidelines/Type Design Guidelines/nested_types"},next:{title:"Struct Design",permalink:"/xtd/docs/documentation/Design Guidelines/Type Design Guidelines/struct_design"}},c={},l=[],u={toc:l},d="wrapper";function p(e){let{components:t,...n}=e;return(0,i.kt)(d,(0,s.Z)({},u,n,{components:t,mdxType:"MDXLayout"}),(0,i.kt)("h1",{id:"static-class-design"},"Static Class Design"),(0,i.kt)("p",null,"A static class is defined as a class that contains only static members (of course besides the instance members inherited from System.Object and possibly a private constructor). C++ languages do not provide built-in support for static classes."),(0,i.kt)("p",null,"Static classes are a compromise between pure object-oriented design and simplicity. They are commonly used to provide shortcuts to other operations (such as xtd::io::file), holders of extension methods, or functionality for which a full object-oriented wrapper is unwarranted (such as xtd::environment)."),(0,i.kt)("p",null,(0,i.kt)("strong",{parentName:"p"},"\u2714\ufe0f DO")," use static classes sparingly."),(0,i.kt)("p",null,"Static classes should be used only as supporting classes for the object-oriented core of the framework."),(0,i.kt)("p",null,(0,i.kt)("strong",{parentName:"p"},"\u274c DO NOT")," treat static classes as a miscellaneous bucket."),(0,i.kt)("p",null,(0,i.kt)("strong",{parentName:"p"},"\u274c DO NOT")," declare or override instance members in static classes."),(0,i.kt)("p",null,(0,i.kt)("strong",{parentName:"p"},"\u2714\ufe0f DO")," declare static classes as abstract, and add a private instance constructor or add xtd keyword static_ because C++ language does not have built-in support for static classes."),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-cpp"},"namespace xtd {\n  class environment static_ {\n  public:\n    static void exit(int exit_code) {\n      ...\n    }\n    ...\n  };\n}\n")),(0,i.kt)("h1",{id:"see-also"},"See also"),(0,i.kt)("p",null,"\u200b"),(0,i.kt)("ul",null,(0,i.kt)("li",{parentName:"ul"},(0,i.kt)("a",{parentName:"li",href:"/docs/documentation/Design%20Guidelines/Type%20Design%20Guidelines"},"Type Design Guidelines")),(0,i.kt)("li",{parentName:"ul"},(0,i.kt)("a",{parentName:"li",href:"/docs/documentation/Design%20Guidelines"},"Design Guidelines")),(0,i.kt)("li",{parentName:"ul"},(0,i.kt)("a",{parentName:"li",href:"/docs/documentation"},"Documentation"))))}p.isMDXComponent=!0}}]);