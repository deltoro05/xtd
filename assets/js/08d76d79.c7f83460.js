"use strict";(self.webpackChunkxtd=self.webpackChunkxtd||[]).push([[3685],{91971:(e,t,n)=>{n.d(t,{Zo:()=>u,kt:()=>h});var a=n(76687);function r(e,t,n){return t in e?Object.defineProperty(e,t,{value:n,enumerable:!0,configurable:!0,writable:!0}):e[t]=n,e}function s(e,t){var n=Object.keys(e);if(Object.getOwnPropertySymbols){var a=Object.getOwnPropertySymbols(e);t&&(a=a.filter((function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable}))),n.push.apply(n,a)}return n}function i(e){for(var t=1;t<arguments.length;t++){var n=null!=arguments[t]?arguments[t]:{};t%2?s(Object(n),!0).forEach((function(t){r(e,t,n[t])})):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(n)):s(Object(n)).forEach((function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(n,t))}))}return e}function o(e,t){if(null==e)return{};var n,a,r=function(e,t){if(null==e)return{};var n,a,r={},s=Object.keys(e);for(a=0;a<s.length;a++)n=s[a],t.indexOf(n)>=0||(r[n]=e[n]);return r}(e,t);if(Object.getOwnPropertySymbols){var s=Object.getOwnPropertySymbols(e);for(a=0;a<s.length;a++)n=s[a],t.indexOf(n)>=0||Object.prototype.propertyIsEnumerable.call(e,n)&&(r[n]=e[n])}return r}var l=a.createContext({}),d=function(e){var t=a.useContext(l),n=t;return e&&(n="function"==typeof e?e(t):i(i({},t),e)),n},u=function(e){var t=d(e.components);return a.createElement(l.Provider,{value:t},e.children)},c="mdxType",p={inlineCode:"code",wrapper:function(e){var t=e.children;return a.createElement(a.Fragment,{},t)}},m=a.forwardRef((function(e,t){var n=e.components,r=e.mdxType,s=e.originalType,l=e.parentName,u=o(e,["components","mdxType","originalType","parentName"]),c=d(n),m=r,h=c["".concat(l,".").concat(m)]||c[m]||p[m]||s;return n?a.createElement(h,i(i({ref:t},u),{},{components:n})):a.createElement(h,i({ref:t},u))}));function h(e,t){var n=arguments,r=t&&t.mdxType;if("string"==typeof e||r){var s=n.length,i=new Array(s);i[0]=m;var o={};for(var l in t)hasOwnProperty.call(t,l)&&(o[l]=t[l]);o.originalType=e,o[c]="string"==typeof e?e:r,i[1]=o;for(var d=2;d<s;d++)i[d]=n[d];return a.createElement.apply(null,i)}return a.createElement.apply(null,n)}m.displayName="MDXCreateElement"},81429:(e,t,n)=>{n.r(t),n.d(t,{assets:()=>l,contentTitle:()=>i,default:()=>p,frontMatter:()=>s,metadata:()=>o,toc:()=>d});var a=n(855),r=(n(76687),n(91971));const s={},i="Event Design",o={unversionedId:"documentation/Design Guidelines/Member Design Guidelines/event_design",id:"documentation/Design Guidelines/Member Design Guidelines/event_design",title:"Event Design",description:"Events are the most commonly used form of callbacks (constructs that allow the framework to call into user code). Other callback mechanisms include members taking delegates, virtual members, and interface-based plug-ins. Data from usability studies indicate that the majority of developers are more comfortable using events than they are using the other callback mechanisms. Events are nicely integrated with xtd.",source:"@site/docs/documentation/Design Guidelines/Member Design Guidelines/event_design.md",sourceDirName:"documentation/Design Guidelines/Member Design Guidelines",slug:"/documentation/Design Guidelines/Member Design Guidelines/event_design",permalink:"/xtd/docs/documentation/Design Guidelines/Member Design Guidelines/event_design",draft:!1,tags:[],version:"current",frontMatter:{},sidebar:"tutorialSidebar",previous:{title:"Constructor Design",permalink:"/xtd/docs/documentation/Design Guidelines/Member Design Guidelines/constructor_design"},next:{title:"Field Design",permalink:"/xtd/docs/documentation/Design Guidelines/Member Design Guidelines/field_design"}},l={},d=[],u={toc:d},c="wrapper";function p(e){let{components:t,...n}=e;return(0,r.kt)(c,(0,a.Z)({},u,n,{components:t,mdxType:"MDXLayout"}),(0,r.kt)("h1",{id:"event-design"},"Event Design"),(0,r.kt)("p",null,"Events are the most commonly used form of callbacks (constructs that allow the framework to call into user code). Other callback mechanisms include members taking delegates, virtual members, and interface-based plug-ins. Data from usability studies indicate that the majority of developers are more comfortable using events than they are using the other callback mechanisms. Events are nicely integrated with xtd."),(0,r.kt)("p",null,"It is important to note that there are two groups of events: events raised before a state of the system changes, called pre-events, and events raised after a state changes, called post-events. An example of a pre-event would be xtd::forms::form::closing, which is raised before a form is closed."),(0,r.kt)("p",null,"An example of a post-event would be xtd::forms::form::closed, which is raised after a form is closed."),(0,r.kt)("p",null,(0,r.kt)("strong",{parentName:"p"},"\u2714\ufe0f DO"),' use the term "raise" for events rather than "fire" or "trigger."'),(0,r.kt)("p",null,(0,r.kt)("strong",{parentName:"p"},"\u2714\ufe0f DO")," use xtd:generic_event_handler <event_args_t> instead of manually creating new delegates to be used as event handlers."),(0,r.kt)("p",null,(0,r.kt)("strong",{parentName:"p"},"\u2714\ufe0f CONSIDER")," using a subclass of xtd::event_args as the event argument, unless you are absolutely sure the event will never need to carry any data to the event handling method, in which case you can use the xtd::event_args type directly."),(0,r.kt)("p",null,"If you ship an API using xtd::event_args directly, you will never be able to add any data to be carried with the event without breaking compatibility. If you use a subclass, even if initially completely empty, you will be able to add properties to the subclass when needed."),(0,r.kt)("p",null,(0,r.kt)("strong",{parentName:"p"},"\u2714\ufe0f DO")," use a public virtual method to raise each event. This is applicable to nonstatic events on classes, or static events."),(0,r.kt)("p",null,'The purpose of the method is to provide a way for a derived class to handle the event using an override. Overriding is a more flexible, faster, and more natural way to handle base class events in derived classes. By convention, the name of the method should start with "on_" and be followed with the name of the event.'),(0,r.kt)("p",null,"The derived class can choose not to call the base implementation of the method in its override. Be prepared for this by not including any processing in the method that is required for the base class to work correctly."),(0,r.kt)("p",null,(0,r.kt)("strong",{parentName:"p"},"\u2714\ufe0f DO")," take one parameter to the method that raises an event."),(0,r.kt)("p",null,"The parameter should be named ",(0,r.kt)("em",{parentName:"p"},"e")," and should be typed as the event argument class."),(0,r.kt)("p",null,(0,r.kt)("strong",{parentName:"p"},"\u274c DO NOT")," pass nullptr as the sender when raising a nonstatic event."),(0,r.kt)("p",null,(0,r.kt)("strong",{parentName:"p"},"\u2714\ufe0f DO")," pass Object as the sender when raising a static event."),(0,r.kt)("p",null,(0,r.kt)("strong",{parentName:"p"},"\u274c DO NOT")," pass nullptr as the event data parameter when raising an event."),(0,r.kt)("p",null,"You should pass xtd::event_args::empty if you don\u2019t want to pass any data to the event handling method. Developers expect this parameter not to be nullptr."),(0,r.kt)("h1",{id:"custom-event-handler-design"},"Custom Event Handler Design"),(0,r.kt)("p",null,(0,r.kt)("strong",{parentName:"p"},"\u2714\ufe0f DO")," use a return type of void for event handlers."),(0,r.kt)("p",null,"An event handler can invoke multiple event handling methods, possibly on multiple objects. If event handling methods were allowed to return a value, there would be multiple return values for each event invocation."),(0,r.kt)("p",null,(0,r.kt)("strong",{parentName:"p"},"\u2714\ufe0f DO")," use object as the type of the first parameter of the event handler, and call it ",(0,r.kt)("em",{parentName:"p"},"sender"),"."),(0,r.kt)("p",null,(0,r.kt)("strong",{parentName:"p"},"\u2714\ufe0f DO")," use xtd::event_args or its subclass as the type of the second parameter of the event handler, and call it ",(0,r.kt)("em",{parentName:"p"},"e"),"."),(0,r.kt)("p",null,(0,r.kt)("strong",{parentName:"p"},"\u274c DO NOT")," have more than two parameters on event handlers."),(0,r.kt)("h1",{id:"see-also"},"See also"),(0,r.kt)("p",null,"\u200b"),(0,r.kt)("ul",null,(0,r.kt)("li",{parentName:"ul"},(0,r.kt)("a",{parentName:"li",href:"/docs/documentation/Design%20Guidelines/Member%20Design%20Guidelines"},"Member Design Guidelines")),(0,r.kt)("li",{parentName:"ul"},(0,r.kt)("a",{parentName:"li",href:"/docs/documentation/Design%20Guidelines"},"Design Guidelines")),(0,r.kt)("li",{parentName:"ul"},(0,r.kt)("a",{parentName:"li",href:"/docs/documentation"},"Documentation"))))}p.isMDXComponent=!0}}]);