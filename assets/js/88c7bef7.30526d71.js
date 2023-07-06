"use strict";(self.webpackChunkxtd=self.webpackChunkxtd||[]).push([[3417],{91971:(e,t,n)=>{n.d(t,{Zo:()=>p,kt:()=>f});var o=n(76687);function r(e,t,n){return t in e?Object.defineProperty(e,t,{value:n,enumerable:!0,configurable:!0,writable:!0}):e[t]=n,e}function i(e,t){var n=Object.keys(e);if(Object.getOwnPropertySymbols){var o=Object.getOwnPropertySymbols(e);t&&(o=o.filter((function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable}))),n.push.apply(n,o)}return n}function a(e){for(var t=1;t<arguments.length;t++){var n=null!=arguments[t]?arguments[t]:{};t%2?i(Object(n),!0).forEach((function(t){r(e,t,n[t])})):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(n)):i(Object(n)).forEach((function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(n,t))}))}return e}function s(e,t){if(null==e)return{};var n,o,r=function(e,t){if(null==e)return{};var n,o,r={},i=Object.keys(e);for(o=0;o<i.length;o++)n=i[o],t.indexOf(n)>=0||(r[n]=e[n]);return r}(e,t);if(Object.getOwnPropertySymbols){var i=Object.getOwnPropertySymbols(e);for(o=0;o<i.length;o++)n=i[o],t.indexOf(n)>=0||Object.prototype.propertyIsEnumerable.call(e,n)&&(r[n]=e[n])}return r}var c=o.createContext({}),l=function(e){var t=o.useContext(c),n=t;return e&&(n="function"==typeof e?e(t):a(a({},t),e)),n},p=function(e){var t=l(e.components);return o.createElement(c.Provider,{value:t},e.children)},u="mdxType",d={inlineCode:"code",wrapper:function(e){var t=e.children;return o.createElement(o.Fragment,{},t)}},m=o.forwardRef((function(e,t){var n=e.components,r=e.mdxType,i=e.originalType,c=e.parentName,p=s(e,["components","mdxType","originalType","parentName"]),u=l(n),m=r,f=u["".concat(c,".").concat(m)]||u[m]||d[m]||i;return n?o.createElement(f,a(a({ref:t},p),{},{components:n})):o.createElement(f,a({ref:t},p))}));function f(e,t){var n=arguments,r=t&&t.mdxType;if("string"==typeof e||r){var i=n.length,a=new Array(i);a[0]=m;var s={};for(var c in t)hasOwnProperty.call(t,c)&&(s[c]=t[c]);s.originalType=e,s[u]="string"==typeof e?e:r,a[1]=s;for(var l=2;l<i;l++)a[l]=n[l];return o.createElement.apply(null,a)}return o.createElement.apply(null,n)}m.displayName="MDXCreateElement"},4477:(e,t,n)=>{n.r(t),n.d(t,{assets:()=>c,contentTitle:()=>a,default:()=>d,frontMatter:()=>i,metadata:()=>s,toc:()=>l});var o=n(855),r=(n(76687),n(91971));const i={},a="Exception Throwing",s={unversionedId:"documentation/Design Guidelines/Design Guidelines for Exception/exception_throwing",id:"documentation/Design Guidelines/Design Guidelines for Exception/exception_throwing",title:"Exception Throwing",description:"Exception-throwing guidelines described in this section require a good definition of the meaning of execution failure. Execution failure occurs whenever a member cannot do what it was designed to do (what the member name implies). For example, if the open_file method cannot return an opened file handle to the caller, it would be considered an execution failure.",source:"@site/docs/documentation/Design Guidelines/Design Guidelines for Exception/exception_throwing.md",sourceDirName:"documentation/Design Guidelines/Design Guidelines for Exception",slug:"/documentation/Design Guidelines/Design Guidelines for Exception/exception_throwing",permalink:"/xtd/docs/documentation/Design Guidelines/Design Guidelines for Exception/exception_throwing",draft:!1,tags:[],version:"current",frontMatter:{},sidebar:"tutorialSidebar",previous:{title:"Design Guidelines for Exception",permalink:"/xtd/docs/documentation/Design Guidelines/Design Guidelines for Exception/"},next:{title:"Exceptions and Performance",permalink:"/xtd/docs/documentation/Design Guidelines/Design Guidelines for Exception/exceptions_and_performance"}},c={},l=[],p={toc:l},u="wrapper";function d(e){let{components:t,...n}=e;return(0,r.kt)(u,(0,o.Z)({},p,n,{components:t,mdxType:"MDXLayout"}),(0,r.kt)("h1",{id:"exception-throwing"},"Exception Throwing"),(0,r.kt)("p",null,"Exception-throwing guidelines described in this section require a good definition of the meaning of execution failure. Execution failure occurs whenever a member cannot do what it was designed to do (what the member name implies). For example, if the open_file method cannot return an opened file handle to the caller, it would be considered an execution failure."),(0,r.kt)("p",null,"Most developers have become comfortable using exceptions for errors such as division by zero or null references. In the Framework, exceptions are used for all error conditions, including execution errors."),(0,r.kt)("p",null,(0,r.kt)("strong",{parentName:"p"},"\u274c DO NOT")," return error codes."),(0,r.kt)("p",null,"Exceptions are the primary means of reporting errors in frameworks."),(0,r.kt)("p",null,(0,r.kt)("strong",{parentName:"p"},"\u2714\ufe0f DO")," report execution failures by throwing exceptions."),(0,r.kt)("p",null,(0,r.kt)("strong",{parentName:"p"},"\u274c DO NOT")," use exceptions for the normal flow of control, if possible."),(0,r.kt)("p",null,"Except for system failures and operations with potential race conditions, framework designers should design APIs so users can write code that does not throw exceptions. For example, you can provide a way to check preconditions before calling a member so users can write code that does not throw exceptions."),(0,r.kt)("p",null,"The member used to check preconditions of another member is often referred to as a tester, and the member that actually does the work is called a doer."),(0,r.kt)("p",null,"There are cases when the ",(0,r.kt)("em",{parentName:"p"},"Tester-Doer")," Pattern can have an unacceptable performance overhead. In such cases, the so-called ",(0,r.kt)("em",{parentName:"p"},"Try-Parse")," Pattern should be considered (see ",(0,r.kt)("a",{parentName:"p",href:"/docs/documentation/Design%20Guidelines/Design%20Guidelines%20for%20Exception/exceptions_and_performance"},"Exceptions and Performance")," for more information)."),(0,r.kt)("p",null,(0,r.kt)("strong",{parentName:"p"},"\u2714\ufe0f CONSIDER")," the performance implications of throwing exceptions. Throw rates above 100 per second are likely to noticeably impact the performance of most applications."),(0,r.kt)("p",null,(0,r.kt)("strong",{parentName:"p"},"\u2714\ufe0f DO")," document all exceptions thrown by publicly callable members because of a violation of the member contract (rather than a system failure) and treat them as part of your contract."),(0,r.kt)("p",null,"Exceptions that are a part of the contract should not change from one version to the next (i.e., exception type should not change, and new exceptions should not be added)."),(0,r.kt)("p",null,(0,r.kt)("strong",{parentName:"p"},"\u274c DO NOT")," have public members that can either throw or not based on some option."),(0,r.kt)("p",null,(0,r.kt)("strong",{parentName:"p"},"\u274c DO NOT")," have public members that return exceptions as the return value or a ref parameter."),(0,r.kt)("p",null,"Returning exceptions from public APIs instead of throwing them defeats many of the benefits of exception-based error reporting."),(0,r.kt)("p",null,(0,r.kt)("strong",{parentName:"p"},"\u2714\ufe0f CONSIDER")," using exception builder methods."),(0,r.kt)("p",null,"It is common to throw the same exception from different places. To avoid code bloat, use helper methods that create exceptions and initialize their properties."),(0,r.kt)("p",null,"Also, members that throw exceptions are not getting inlined. Moving the throw statement inside the builder might allow the member to be inlined."),(0,r.kt)("p",null,(0,r.kt)("strong",{parentName:"p"},"\u274c DO NOT")," throw exceptions from exception filter blocks."),(0,r.kt)("h1",{id:"see-also"},"See also"),(0,r.kt)("p",null,"\u200b"),(0,r.kt)("ul",null,(0,r.kt)("li",{parentName:"ul"},(0,r.kt)("a",{parentName:"li",href:"/docs/documentation/Design%20Guidelines/Design%20Guidelines%20for%20Exception"},"Design Guidelines for Exception")),(0,r.kt)("li",{parentName:"ul"},(0,r.kt)("a",{parentName:"li",href:"/docs/documentation/Design%20Guidelines"},"Design Guidelines")),(0,r.kt)("li",{parentName:"ul"},(0,r.kt)("a",{parentName:"li",href:"/docs/documentation"},"Documentation"))))}d.isMDXComponent=!0}}]);