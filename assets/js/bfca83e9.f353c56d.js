"use strict";(self.webpackChunkxtd=self.webpackChunkxtd||[]).push([[3825],{91971:(t,e,r)=>{r.d(e,{Zo:()=>d,kt:()=>f});var a=r(76687);function n(t,e,r){return e in t?Object.defineProperty(t,e,{value:r,enumerable:!0,configurable:!0,writable:!0}):t[e]=r,t}function o(t,e){var r=Object.keys(t);if(Object.getOwnPropertySymbols){var a=Object.getOwnPropertySymbols(t);e&&(a=a.filter((function(e){return Object.getOwnPropertyDescriptor(t,e).enumerable}))),r.push.apply(r,a)}return r}function i(t){for(var e=1;e<arguments.length;e++){var r=null!=arguments[e]?arguments[e]:{};e%2?o(Object(r),!0).forEach((function(e){n(t,e,r[e])})):Object.getOwnPropertyDescriptors?Object.defineProperties(t,Object.getOwnPropertyDescriptors(r)):o(Object(r)).forEach((function(e){Object.defineProperty(t,e,Object.getOwnPropertyDescriptor(r,e))}))}return t}function s(t,e){if(null==t)return{};var r,a,n=function(t,e){if(null==t)return{};var r,a,n={},o=Object.keys(t);for(a=0;a<o.length;a++)r=o[a],e.indexOf(r)>=0||(n[r]=t[r]);return n}(t,e);if(Object.getOwnPropertySymbols){var o=Object.getOwnPropertySymbols(t);for(a=0;a<o.length;a++)r=o[a],e.indexOf(r)>=0||Object.prototype.propertyIsEnumerable.call(t,r)&&(n[r]=t[r])}return n}var l=a.createContext({}),m=function(t){var e=a.useContext(l),r=e;return t&&(r="function"==typeof t?t(e):i(i({},e),t)),r},d=function(t){var e=m(t.components);return a.createElement(l.Provider,{value:e},t.children)},u="mdxType",p={inlineCode:"code",wrapper:function(t){var e=t.children;return a.createElement(a.Fragment,{},e)}},c=a.forwardRef((function(t,e){var r=t.components,n=t.mdxType,o=t.originalType,l=t.parentName,d=s(t,["components","mdxType","originalType","parentName"]),u=m(r),c=n,f=u["".concat(l,".").concat(c)]||u[c]||p[c]||o;return r?a.createElement(f,i(i({ref:e},d),{},{components:r})):a.createElement(f,i({ref:e},d))}));function f(t,e){var r=arguments,n=e&&e.mdxType;if("string"==typeof t||n){var o=r.length,i=new Array(o);i[0]=c;var s={};for(var l in e)hasOwnProperty.call(e,l)&&(s[l]=e[l]);s.originalType=t,s[u]="string"==typeof t?t:n,i[1]=s;for(var m=2;m<o;m++)i[m]=r[m];return a.createElement.apply(null,i)}return a.createElement.apply(null,r)}c.displayName="MDXCreateElement"},22466:(t,e,r)=>{r.r(e),r.d(e,{assets:()=>l,contentTitle:()=>i,default:()=>p,frontMatter:()=>o,metadata:()=>s,toc:()=>m});var a=r(855),n=(r(76687),r(91971));const o={},i="Format",s={unversionedId:"documentation/Guides/xtd.core/Format number dates other types/standard_numeric_format_strings",id:"documentation/Guides/xtd.core/Format number dates other types/standard_numeric_format_strings",title:"Format",description:"Contains formatting converting documentation.",source:"@site/docs/documentation/Guides/xtd.core/Format number dates other types/standard_numeric_format_strings.md",sourceDirName:"documentation/Guides/xtd.core/Format number dates other types",slug:"/documentation/Guides/xtd.core/Format number dates other types/standard_numeric_format_strings",permalink:"/xtd/docs/documentation/Guides/xtd.core/Format number dates other types/standard_numeric_format_strings",draft:!1,tags:[],version:"current",frontMatter:{},sidebar:"tutorialSidebar",previous:{title:"Standard date and time format strings",permalink:"/xtd/docs/documentation/Guides/xtd.core/Format number dates other types/standard_date_and_time_format_strings"},next:{title:"Standard time_span format strings",permalink:"/xtd/docs/documentation/Guides/xtd.core/Format number dates other types/standard_time_span_format_strings"}},l={},m=[{value:"Formatting Types",id:"formatting-types",level:2},{value:"Notes",id:"notes",level:3},{value:"Formating",id:"formating",level:2},{value:"Composite Formatting",id:"composite-formatting",level:2},{value:"Composite Format String",id:"composite-format-string",level:2}],d={toc:m},u="wrapper";function p(t){let{components:e,...r}=t;return(0,n.kt)(u,(0,a.Z)({},d,r,{components:e,mdxType:"MDXLayout"}),(0,n.kt)("h1",{id:"format"},"Format"),(0,n.kt)("p",null,"Contains formatting converting documentation."),(0,n.kt)("h2",{id:"formatting-types"},"Formatting Types"),(0,n.kt)("p",null,"Formatting is the process of converting an instance of a class, structure, or enumeration value to its string representation, often so that the resulting string can be displayed to users or deserialized to restore the original data type. This conversion can pose a number of challenges:"),(0,n.kt)("ul",null,(0,n.kt)("li",{parentName:"ul"},"The way that values are stored internally does not necessarily reflect the way that users want to view them. For example, a telephone number might be stored in the form 8009999999, which is not user-friendly. It should instead be displayed as 800-999-9999. See the ",(0,n.kt)("a",{parentName:"li",href:"#custom-format-strings"},"Custom Format Strings")," section for an example that formats a number in this way."),(0,n.kt)("li",{parentName:"ul"},"Sometimes the conversion of an object to its string representation is not intuitive. For example, it is not clear how the string representation of a Temperature object or a Person object should appear. For an example that formats a Temperature object in a variety of ways, see the ","[Standard Format Strings(standard-format-strings)]"," section."),(0,n.kt)("li",{parentName:"ul"},"Values often require culture-sensitive formatting. For example, in an application that uses numbers to reflect monetary values, numeric strings should include the current culture\u2019s currency symbol, group separator (which, in most cultures, is the thousands separator), and decimal symbol."),(0,n.kt)("li",{parentName:"ul"},"An application may have to display the same value in different ways. For example, an application may represent an enumeration member by displaying a string representation of its name or by displaying its underlying value. For an example that formats a member of the day_of_week enumeration in different ways, see the ",(0,n.kt)("a",{parentName:"li",href:"#standard-format-strings"},"Standard Format Strings")," section.")),(0,n.kt)("h3",{id:"notes"},"Notes"),(0,n.kt)("p",null,"Formatting converts the value of a type into a string representation. Parsing is the inverse of formatting. A parsing operation creates an instance of a data type from its string representation."),(0,n.kt)("p",null,"xtd provides rich formatting support that enables developers to address these requirements."),(0,n.kt)("p",null,"This overview contains the following sections:"),(0,n.kt)("ul",null,(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("a",{parentName:"li",href:"#formatting"},"Formatting")),(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("a",{parentName:"li",href:"#defaultf-formatting-using-operator-shift-left"},"Default Formatting Using Operator Shift Left")),(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("a",{parentName:"li",href:"#overriding-shift-left-operator-method"},"Overriding Shift Left operator Method")),(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("a",{parentName:"li",href:"#to_string-method-and-format-strings"},"to_string Method And Format Strings"),(0,n.kt)("ul",{parentName:"li"},(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("a",{parentName:"li",href:"#standard-format-strings"},"Standard Format Strings")),(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("a",{parentName:"li",href:"#custom-format-strings"},"Custom Format Strings")),(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("a",{parentName:"li",href:"#format-strings-and-types"},"Format Strings And Types")))),(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("a",{parentName:"li",href:"#culture-sensitive-formatting"},"Culture Sensitive Formatting"),(0,n.kt)("ul",{parentName:"li"},(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("a",{parentName:"li",href:"#culture-sensitive-formatting-of-numeric-values"},"Culture Sensitive Formatting Of Numeric Values")),(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("a",{parentName:"li",href:"#culture-sensitive-formatting-of-date-and-time-values"},"Culture Sensitive Formatting Of Date And Time Values")))),(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("a",{parentName:"li",href:"#culture-sensitive-formatting"},"Culture Sensitive Formatting")),(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("a",{parentName:"li",href:"#composite-formatting"},"Composite Formatting")),(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("a",{parentName:"li",href:"#custom-formatting"},"Custom Formatting")),(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("a",{parentName:"li",href:"#related-topics"},"Related Topics")),(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("a",{parentName:"li",href:"#reference"},"Reference"))),(0,n.kt)("h2",{id:"formating"},"Formating"),(0,n.kt)("p",null,"The basic mechanism for formatting is the default implementation of the operator ",(0,n.kt)("inlineCode",{parentName:"p"},"<<")," object method, which is discussed in the ",(0,n.kt)("a",{parentName:"p",href:"#default-formatting-using-operator-shift-left"},"Default Formatting Using Operator Shift Left")," section later in this topic. xtd.Strings provides several ways to modify and extend its default formatting support. These include the following:"),(0,n.kt)("ul",null,(0,n.kt)("li",{parentName:"ul"},"Overriding the operator ",(0,n.kt)("inlineCode",{parentName:"li"},"<<")," object method to define a custom string representation of an object\u2019s value. For more information, see the ",(0,n.kt)("a",{parentName:"li",href:"#overriding-shift-left-operator-method%5D"},"Overriding Shift Left Operator Method")," section later in this topic."),(0,n.kt)("li",{parentName:"ul"},'Defining format specifiers that enable the string representation of an object\u2019s value to take multiple forms. For example, the "X" format specifier in the following statement converts an integer to the string representation of a hexadecimal value.')),(0,n.kt)("pre",null,(0,n.kt)("code",{parentName:"pre",className:"language-cpp"},'int integer_value = 60312;\nxtd::console::write_line(xtd::to_string(integer_value, "X"));   // Displays EB98.\n')),(0,n.kt)("p",null,"For more information about format specifiers, see the ",(0,n.kt)("a",{parentName:"p",href:"#to_string-method-and-format-strings"},"to_string Method And Format Strings")," section."),(0,n.kt)("ul",null,(0,n.kt)("li",{parentName:"ul"},"Using format providers to take advantage of the formatting conventions of a specific culture. For example, the following statement displays a currency value by using the formatting conventions of the en-US culture.")),(0,n.kt)("pre",null,(0,n.kt)("code",{parentName:"pre",className:"language-cpp"},'double cost = 1632.54;\nxtd::console::write_line(xtd::to_string(cost, "C", std::locale("en_US.UTF-8")));\n// The example displays the following output:\n//\n// $1,632.54\n')),(0,n.kt)("p",null,"For more information about formatting with format providers, see the ",(0,n.kt)("a",{parentName:"p",href:"#culture-sensitive-formatting"},"Culture Sensitive Formatting")," section."),(0,n.kt)("p",null,"Using composite formatting to embed the string representation of a value in a larger string. For more information, see the ",(0,n.kt)("a",{parentName:"p",href:"#composite-formatting"},"Composite Formatting")," section."),(0,n.kt)("p",null,"The following sections examine these methods for converting an object to its string representation."),(0,n.kt)("h2",{id:"composite-formatting"},"Composite Formatting"),(0,n.kt)("p",null,"The composite formatting feature takes a list of objects and a composite format string as input. A composite format string consists of fixed text intermixed with indexed placeholders, called format items, that correspond to the objects in the list. The formatting operation yields a result string that consists of the original fixed text intermixed with the string representation of the objects in the list."),(0,n.kt)("p",null,"The composite formatting feature is supported by methods such as the following:"),(0,n.kt)("ul",null,(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("a",{parentName:"li",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/group__format__parse.html#ga3afd6d163bc6391a48a1f84f28a68ffd"},"xtd::ustring::format"),", which returns a formatted result string (xtd library)."),(0,n.kt)("li",{parentName:"ul"},"Some overloads of the ",(0,n.kt)("a",{parentName:"li",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1console.html#aa9fbf20d808213c547163d5e7101bcda"},"xtd::console::write_line")," method, which display a formatted result string to the console (",(0,n.kt)("a",{parentName:"li",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html"},"xtd.core")," library)."),(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("a",{parentName:"li",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1diagnostics_1_1debug.html#a2656cc128804128258ecad60ecf1cbd1"},"xtd::diagnostics::debug::write_line")," method, which outputs a formatted message to trace listeners (",(0,n.kt)("a",{parentName:"li",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html"},"xtd.core")," library)."),(0,n.kt)("li",{parentName:"ul"},"The ",(0,n.kt)("a",{parentName:"li",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1diagnostics_1_1trace.html#a961460d0f10e5a3a36cfa2ecc222687a"},"xtd::diagnostics::trace::trace_error"),", ",(0,n.kt)("a",{parentName:"li",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1diagnostics_1_1trace.html#ae6444d92dadb5325844ed01313384335"},"xtd::diagnostics::trace::trace_information"),", and ",(0,n.kt)("a",{parentName:"li",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1diagnostics_1_1trace.html#a8500d77e87bea7e8b021d1530e403850"},"xtd::diagnostics::trace::trace_warning")," methods, which output formatted messages to trace listeners (xtd.core library).")),(0,n.kt)("h2",{id:"composite-format-string"},"Composite Format String"),(0,n.kt)("p",null,"A composite format string and object list are used as arguments of methods that support the composite formatting feature. A composite format string consists of zero or more runs of fixed text intermixed with one or more format items. The fixed text is any string that you choose, and each format item corresponds to an object or boxed structure in the list. The composite formatting feature returns a new result string where each format item is replaced by the string representation of the corresponding object in the list."),(0,n.kt)("p",null,"Consider the following ",(0,n.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/group__format__parse.html#ga3afd6d163bc6391a48a1f84f28a68ffd"},"xtd::ustring::format")," code fragment."),(0,n.kt)("pre",null,(0,n.kt)("code",{parentName:"pre",className:"language-cpp"},'string name = "Fred";\nxtd::ustring::format("Name = {0}, age = {1:D3}", name, 42);\n')),(0,n.kt)("p",null,"The fixed text is ",(0,n.kt)("inlineCode",{parentName:"p"},"name = ")," and ",(0,n.kt)("inlineCode",{parentName:"p"},", age = "),'. The format items are "{0}", whose index is 0, which corresponds to the object name, and "{1:D3}", whose index is 1, which corresponds to the integer 42.'),(0,n.kt)("h1",{id:"see-also"},"See also"),(0,n.kt)("p",null,"\u200b"),(0,n.kt)("ul",null,(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("a",{parentName:"li",href:"/docs/documentation/Guides/Overview/Tutorials"},"Tutorials")),(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("a",{parentName:"li",href:"/docs/documentation"},"Documentation"))))}p.isMDXComponent=!0}}]);