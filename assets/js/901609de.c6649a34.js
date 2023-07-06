"use strict";(self.webpackChunkxtd=self.webpackChunkxtd||[]).push([[784],{91971:(e,t,r)=>{r.d(t,{Zo:()=>i,kt:()=>u});var a=r(76687);function o(e,t,r){return t in e?Object.defineProperty(e,t,{value:r,enumerable:!0,configurable:!0,writable:!0}):e[t]=r,e}function n(e,t){var r=Object.keys(e);if(Object.getOwnPropertySymbols){var a=Object.getOwnPropertySymbols(e);t&&(a=a.filter((function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable}))),r.push.apply(r,a)}return r}function s(e){for(var t=1;t<arguments.length;t++){var r=null!=arguments[t]?arguments[t]:{};t%2?n(Object(r),!0).forEach((function(t){o(e,t,r[t])})):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(r)):n(Object(r)).forEach((function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(r,t))}))}return e}function d(e,t){if(null==e)return{};var r,a,o=function(e,t){if(null==e)return{};var r,a,o={},n=Object.keys(e);for(a=0;a<n.length;a++)r=n[a],t.indexOf(r)>=0||(o[r]=e[r]);return o}(e,t);if(Object.getOwnPropertySymbols){var n=Object.getOwnPropertySymbols(e);for(a=0;a<n.length;a++)r=n[a],t.indexOf(r)>=0||Object.prototype.propertyIsEnumerable.call(e,r)&&(o[r]=e[r])}return o}var l=a.createContext({}),c=function(e){var t=a.useContext(l),r=t;return e&&(r="function"==typeof e?e(t):s(s({},t),e)),r},i=function(e){var t=c(e.components);return a.createElement(l.Provider,{value:t},e.children)},m="mdxType",h={inlineCode:"code",wrapper:function(e){var t=e.children;return a.createElement(a.Fragment,{},t)}},f=a.forwardRef((function(e,t){var r=e.components,o=e.mdxType,n=e.originalType,l=e.parentName,i=d(e,["components","mdxType","originalType","parentName"]),m=c(r),f=o,u=m["".concat(l,".").concat(f)]||m[f]||h[f]||n;return r?a.createElement(u,s(s({ref:t},i),{},{components:r})):a.createElement(u,s({ref:t},i))}));function u(e,t){var r=arguments,o=t&&t.mdxType;if("string"==typeof e||o){var n=r.length,s=new Array(n);s[0]=f;var d={};for(var l in t)hasOwnProperty.call(t,l)&&(d[l]=t[l]);d.originalType=e,d[m]="string"==typeof e?e:o,s[1]=d;for(var c=2;c<n;c++)s[c]=r[c];return a.createElement.apply(null,s)}return a.createElement.apply(null,r)}f.displayName="MDXCreateElement"},42619:(e,t,r)=>{r.r(t),r.d(t,{assets:()=>l,contentTitle:()=>s,default:()=>h,frontMatter:()=>n,metadata:()=>d,toc:()=>c});var a=r(855),o=(r(76687),r(91971));const n={},s="How to make thread-safe calls to controls (xtd.forms)",d={unversionedId:"documentation/Guides/xtd.forms/Controls/Common tasks/thread_safe_control_call",id:"documentation/Guides/xtd.forms/Controls/Common tasks/thread_safe_control_call",title:"How to make thread-safe calls to controls (xtd.forms)",description:"In This Section",source:"@site/docs/documentation/Guides/xtd.forms/Controls/Common tasks/thread_safe_control_call.md",sourceDirName:"documentation/Guides/xtd.forms/Controls/Common tasks",slug:"/documentation/Guides/xtd.forms/Controls/Common tasks/thread_safe_control_call",permalink:"/xtd/docs/documentation/Guides/xtd.forms/Controls/Common tasks/thread_safe_control_call",draft:!1,tags:[],version:"current",frontMatter:{},sidebar:"tutorialSidebar",previous:{title:"How to: Set the text displayed by a control (xtd.forms)",permalink:"/xtd/docs/documentation/Guides/xtd.forms/Controls/Common tasks/set_the_text_displayed_by_a_control"},next:{title:"Common events (xtd.forms)",permalink:"/xtd/docs/documentation/Guides/xtd.forms/Controls/Events"}},l={},c=[{value:"In This Section",id:"in-this-section",level:2},{value:"Overview",id:"overview",level:2},{value:"Unsafe cross-thread calls",id:"unsafe-cross-thread-calls",level:2},{value:"Warning",id:"warning",level:3},{value:"Safe cross-thread calls",id:"safe-cross-thread-calls",level:2},{value:"Example: Use the xtd::forms::control::invoke method",id:"example-use-the-xtdformscontrolinvoke-method",level:3},{value:"Example: Use a xtd::forms::background_worker",id:"example-use-a-xtdformsbackground_worker",level:3},{value:"See also",id:"see-also",level:2}],i={toc:c},m="wrapper";function h(e){let{components:t,...r}=e;return(0,o.kt)(m,(0,a.Z)({},i,r,{components:t,mdxType:"MDXLayout"}),(0,o.kt)("h1",{id:"how-to-make-thread-safe-calls-to-controls-xtdforms"},"How to make thread-safe calls to controls (xtd.forms)"),(0,o.kt)("h2",{id:"in-this-section"},"In This Section"),(0,o.kt)("ul",null,(0,o.kt)("li",{parentName:"ul"},(0,o.kt)("a",{parentName:"li",href:"#overview"},"Overview")),(0,o.kt)("li",{parentName:"ul"},(0,o.kt)("a",{parentName:"li",href:"#unsafe-cross-thread-calls"},"Unsafe cross-thread calls")),(0,o.kt)("li",{parentName:"ul"},(0,o.kt)("a",{parentName:"li",href:"#safe-cross-thread-calls"},"Safe cross-thread calls"))),(0,o.kt)("h2",{id:"overview"},"Overview"),(0,o.kt)("p",null,"Multithreading can improve the performance of xtd.forms applications, but access to xtd.forms controls is not inherently thread-safe.\nMultithreading can expose your code to serious and complex bugs.\nTwo or more threads manipulating a control can force the control into an inconsistent state and lead to race conditions, deadlocks, freezes, or stalls.\nIf you implement multithreading in your application, be sure to call cross-threaded controls in a safe manner."),(0,o.kt)("p",null,"There are two ways to safely call an xtd.forms control from a thread that did not create the control.\nUse the ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html#a17ec51282322d8387937dc8dad438e32"},"xtd::windows::forms::control::invoke")," method to call a delegate created in the main thread, which in turn calls the control.\nYou can also implement an ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1background__worker.html"},"xtd::forms::background_worker"),", which uses an event-driven model to separate the work done in the background thread from the communication of results."),(0,o.kt)("h2",{id:"unsafe-cross-thread-calls"},"Unsafe cross-thread calls"),(0,o.kt)("p",null,"It's unsafe to call a control directly from a thread that didn't create it.\nThe following code snippet illustrates an unsafe call to the ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1text__box.html"},"xtd::forms::text_box")," control.\nThe ",(0,o.kt)("inlineCode",{parentName:"p"},"button1_Click")," event handler creates a new ",(0,o.kt)("inlineCode",{parentName:"p"},"write_text_unsafe")," thread, which sets the main thread's ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1text__box.html#a2d900fe81bd0963d26d36a3a20e1d03e"},"xtd::forms::text_box::text")," property directly."),(0,o.kt)("pre",null,(0,o.kt)("code",{parentName:"pre",className:"language-cpp"},'void button1_click(object& sender, const event_args& e) {\n  thread thread1(delegate<void()>(*this, &main_form::write_text_unsafe));\n  thread1.detach();\n}\n\nvoid write_text_unsafe() {\n  text_box1.text("This text was set unsafely.");\n}\n')),(0,o.kt)("p",null,"The Visual Studio debugger detects these unsafe thread calls by throwing an ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1invalid__operation__exception.html"},"xtd::invalid_operation_exception"),' with the following message: "Cross-thread operation not valid.\nControl accessed from a thread other than the one where it was created.\nThe ',(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1invalid__operation__exception.html"},"xtd::invalid_operation_exception")," always occurs for unsafe cross-threaded calls during Visual Studio debugging, and can occur at application runtime.\nYou need to resolve this issue, but you can disable the exception by setting the ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html#ae50cc5d50f092033848aec2689e5df44"},"xtd::forms::control::check_for_illegal_cross_thread_calls")," property to false."),(0,o.kt)("h3",{id:"warning"},"Warning"),(0,o.kt)("p",null,(0,o.kt)("strong",{parentName:"p"},"Be careful, some OS don't support cross-thread UI operations!")),(0,o.kt)("h2",{id:"safe-cross-thread-calls"},"Safe cross-thread calls"),(0,o.kt)("p",null,"The following code examples demonstrate two ways to safely call a xtd.forms control from a thread that didn't create it:"),(0,o.kt)("ol",null,(0,o.kt)("li",{parentName:"ol"},"The ",(0,o.kt)("a",{parentName:"li",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html#a17ec51282322d8387937dc8dad438e32"},"xtd::forms::control::invoke")," method, which calls a delegate from the main thread to call the control."),(0,o.kt)("li",{parentName:"ol"},"A ",(0,o.kt)("a",{parentName:"li",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1background__worker.html"},"xtd::forms::background_worker")," component, which offers an event-driven model.")),(0,o.kt)("p",null,"In both examples, the background thread sleeps for one second to simulate work being done in that thread."),(0,o.kt)("h3",{id:"example-use-the-xtdformscontrolinvoke-method"},"Example: Use the ",(0,o.kt)("a",{parentName:"h3",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html#a17ec51282322d8387937dc8dad438e32"},"xtd::forms::control::invoke")," method"),(0,o.kt)("p",null,"The following example demonstrates a pattern for ensuring thread-safe calls to a xtd.forms control. It queries the ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html#a7aa968c54c4a100d35f0dd2d0b9c5bc8"},"xtd::forms::control::invoke_required")," property, which compares the control's creating thread ID to the calling thread ID. If they're different, you should call the ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html#a17ec51282322d8387937dc8dad438e32"},"xtd::forms::control::invoke")," method."),(0,o.kt)("p",null,"The ",(0,o.kt)("em",{parentName:"p"},"write_text_safe")," enables setting the ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1text__box.html"},"xtd::forms::text_box")," control's ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html#a4c3b78843745277a88831bd0500ccb2b"},"xtd::forms::control::text")," property to a new value. The method queries ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html#a7aa968c54c4a100d35f0dd2d0b9c5bc8"},"xtd::forms::control::invoke_required"),". If ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html#a7aa968c54c4a100d35f0dd2d0b9c5bc8"},"xtd::forms::control::invoke_required")," returns true, ",(0,o.kt)("inlineCode",{parentName:"p"},"write_text_safe")," recursively calls itself, passing the method as a delegate to the ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html#a17ec51282322d8387937dc8dad438e32"},"xtd::forms::control::invoke")," method. If ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html#a7aa968c54c4a100d35f0dd2d0b9c5bc8"},"xtd::forms::control::invoke_required")," returns false, ",(0,o.kt)("inlineCode",{parentName:"p"},"write_text_safe")," sets the ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1text__box.html#a2d900fe81bd0963d26d36a3a20e1d03e"},"xtd::forms::text_box::text")," directly. The ",(0,o.kt)("inlineCode",{parentName:"p"},"button1_click")," event handler creates the new thread and runs the ",(0,o.kt)("inlineCode",{parentName:"p"},"write_text_safe")," method."),(0,o.kt)("pre",null,(0,o.kt)("code",{parentName:"pre",className:"language-cpp"},'void button1_click(object& sender, const event_args& e) {\n  thread thread1(delegate<void()>(*this, &main_form::write_text_safe));\n  thread1.detach();\n}\n\nvoid write_text_safe() {\n  if (text_box1.invoke_required())\n    text_box1.invoke({*this, &main_form::write_text_safe});\n  else\n    text_box1.text("This text was set safely.");\n}\n')),(0,o.kt)("h3",{id:"example-use-a-xtdformsbackground_worker"},"Example: Use a ",(0,o.kt)("a",{parentName:"h3",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1background__worker.html"},"xtd::forms::background_worker")),(0,o.kt)("p",null,"An easy way to implement multithreading is with the ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1background__worker.html"},"xtd::forms::background_worker")," component, which uses an event-driven model. The background thread raises the ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#gaa4047b732cf383aa932c806080d03216"},"xtd::forms::background_worker::do_work")," event, which doesn't interact with the main thread. The main thread runs the ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga01b056bb600ffc6552edff4830361bf4"},"xtd::forms::background_worker::progress_changed")," and ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga08a598bc14af024ea2a9d16b18925f22"},"xtd::forms::background_worker::run_worker_completed")," event handlers, which can call the main thread's controls."),(0,o.kt)("p",null,"To make a thread-safe call by using ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1background__worker.html"},"xtd::forms::background_worker"),", handle the ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#gaa4047b732cf383aa932c806080d03216"},"xtd::forms::background_worker::do_work")," event. There are two events the background worker uses to report status: ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga01b056bb600ffc6552edff4830361bf4"},"xtd::forms::background_worker::progress_changed")," and ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga08a598bc14af024ea2a9d16b18925f22"},"xtd::forms::background_worker::run_worker_completed"),". The ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga01b056bb600ffc6552edff4830361bf4"},"xtd::forms::background_worker::progress_changed")," event is used to communicate status updates to the main thread, and the ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga08a598bc14af024ea2a9d16b18925f22"},"xtd::forms::background_worker::run_worker_completed")," event is used to signal that the background worker has completed its work. To start the background thread, call ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1background__worker.html#a3c1a81605e6f790fe68cf021f80f1952"},"xtd::forms::background_worker::run_worker_async"),"."),(0,o.kt)("p",null,"The example counts from 0 to 10 in the ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#gaa4047b732cf383aa932c806080d03216"},"xtd::forms::background_worker::do_work")," event, pausing for one second between counts. It uses the ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga01b056bb600ffc6552edff4830361bf4"},"xtd::forms::background_worker::progress_changed")," event handler to report the number back to the main thread and set the ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1text__box.html"},"xtd::forms::text_box")," control's ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1text__box.html#a2d900fe81bd0963d26d36a3a20e1d03e"},"xtd::forms::text_box::text")," property. For the ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga01b056bb600ffc6552edff4830361bf4"},"xtd::forms::background_worker::progress_changed")," event to work, the ",(0,o.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1background__worker.html#afcf2c17c7516752565718de4098b366a"},"xtd::forms::background_worker::worker_reports_progress")," property must be set to true."),(0,o.kt)("pre",null,(0,o.kt)("code",{parentName:"pre",className:"language-cpp"},'void button1_click(object& sender, const event_args& e) {\n  if (!background_worker1.is_busy())\n    background_worker1.run_worker_async();\n}\n\nvoid background_worker1_do_work(object& sender, do_work_event_args& e) {\n  int counter = 0;\n  int max = 10;\n  \n  while (counter <= max) {\n    background_worker1.report_progress(0, ustring::format("{}", counter));\n    this_thread::sleep_for(chrono::milliseconds(1000));\n    counter++;\n  }\n}\n\nvoid background_worker1_progress_changed(object& sender, const progress_changed_event_args& e) {\n  text_box1.text(as<ustring>(e.user_state()));\n}\n')),(0,o.kt)("h2",{id:"see-also"},"See also"),(0,o.kt)("ul",null,(0,o.kt)("li",{parentName:"ul"},(0,o.kt)("a",{parentName:"li",href:"/docs/documentation/Guides"},"Guides")),(0,o.kt)("li",{parentName:"ul"},(0,o.kt)("a",{parentName:"li",href:"/docs/documentation"},"Documentation"))))}h.isMDXComponent=!0}}]);