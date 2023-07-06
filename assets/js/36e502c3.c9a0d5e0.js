"use strict";(self.webpackChunkxtd=self.webpackChunkxtd||[]).push([[2815],{91971:(e,t,n)=>{n.d(t,{Zo:()=>u,kt:()=>h});var s=n(76687);function a(e,t,n){return t in e?Object.defineProperty(e,t,{value:n,enumerable:!0,configurable:!0,writable:!0}):e[t]=n,e}function r(e,t){var n=Object.keys(e);if(Object.getOwnPropertySymbols){var s=Object.getOwnPropertySymbols(e);t&&(s=s.filter((function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable}))),n.push.apply(n,s)}return n}function i(e){for(var t=1;t<arguments.length;t++){var n=null!=arguments[t]?arguments[t]:{};t%2?r(Object(n),!0).forEach((function(t){a(e,t,n[t])})):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(n)):r(Object(n)).forEach((function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(n,t))}))}return e}function l(e,t){if(null==e)return{};var n,s,a=function(e,t){if(null==e)return{};var n,s,a={},r=Object.keys(e);for(s=0;s<r.length;s++)n=r[s],t.indexOf(n)>=0||(a[n]=e[n]);return a}(e,t);if(Object.getOwnPropertySymbols){var r=Object.getOwnPropertySymbols(e);for(s=0;s<r.length;s++)n=r[s],t.indexOf(n)>=0||Object.prototype.propertyIsEnumerable.call(e,n)&&(a[n]=e[n])}return a}var c=s.createContext({}),o=function(e){var t=s.useContext(c),n=t;return e&&(n="function"==typeof e?e(t):i(i({},t),e)),n},u=function(e){var t=o(e.components);return s.createElement(c.Provider,{value:t},e.children)},p="mdxType",d={inlineCode:"code",wrapper:function(e){var t=e.children;return s.createElement(s.Fragment,{},t)}},m=s.forwardRef((function(e,t){var n=e.components,a=e.mdxType,r=e.originalType,c=e.parentName,u=l(e,["components","mdxType","originalType","parentName"]),p=o(n),m=a,h=p["".concat(c,".").concat(m)]||p[m]||d[m]||r;return n?s.createElement(h,i(i({ref:t},u),{},{components:n})):s.createElement(h,i({ref:t},u))}));function h(e,t){var n=arguments,a=t&&t.mdxType;if("string"==typeof e||a){var r=n.length,i=new Array(r);i[0]=m;var l={};for(var c in t)hasOwnProperty.call(t,c)&&(l[c]=t[c]);l.originalType=e,l[p]="string"==typeof e?e:a,i[1]=l;for(var o=2;o<r;o++)i[o]=n[o];return s.createElement.apply(null,i)}return s.createElement.apply(null,n)}m.displayName="MDXCreateElement"},89391:(e,t,n)=>{n.r(t),n.d(t,{assets:()=>c,contentTitle:()=>i,default:()=>d,frontMatter:()=>r,metadata:()=>l,toc:()=>o});var s=n(855),a=(n(76687),n(91971));const r={},i="Test class (test_class)",l={unversionedId:"documentation/Guides/Overview/Tutorials/test_class",id:"documentation/Guides/Overview/Tutorials/test_class",title:"Test class (test_class)",description:"This is the inherited class that marks a class that contains tests and, optionally, setup or teardown methods.",source:"@site/docs/documentation/Guides/Overview/Tutorials/test_class.md",sourceDirName:"documentation/Guides/Overview/Tutorials",slug:"/documentation/Guides/Overview/Tutorials/test_class",permalink:"/xtd/docs/documentation/Guides/Overview/Tutorials/test_class",draft:!1,tags:[],version:"current",frontMatter:{},sidebar:"tutorialSidebar",previous:{title:"Ignore test method (ignore_test_method)",permalink:"/xtd/docs/documentation/Guides/Overview/Tutorials/ingore_test_method"},next:{title:"Test cleanup (test_cleanup)",permalink:"/xtd/docs/documentation/Guides/Overview/Tutorials/test_cleanup"}},c={},o=[{value:"Classic test_class",id:"classic-test_class",level:2},{value:"Generic test_class",id:"generic-test_class",level:2},{value:"Inheritance",id:"inheritance",level:2},{value:"See also",id:"see-also",level:2}],u={toc:o},p="wrapper";function d(e){let{components:t,...n}=e;return(0,a.kt)(p,(0,s.Z)({},u,n,{components:t,mdxType:"MDXLayout"}),(0,a.kt)("h1",{id:"test-class-test_class"},"Test class (test_class)"),(0,a.kt)("p",null,"This is the inherited class that marks a class that contains tests and, optionally, setup or teardown methods."),(0,a.kt)("p",null,"Most restrictions on a class that is used as a test fixture have now been eliminated. A test fixture class:"),(0,a.kt)("ul",null,(0,a.kt)("li",{parentName:"ul"},"May be generic, so long as any type parameters are provided or can be inferred from the actual arguments."),(0,a.kt)("li",{parentName:"ul"},"May not be abstract - although the attribute may be applied to an abstract class intended to serve as a base class for test fixtures."),(0,a.kt)("li",{parentName:"ul"},"Only default constructor may be defined."),(0,a.kt)("li",{parentName:"ul"},"Other parametrized constructor can not be defined.")),(0,a.kt)("p",null,"If any of these restrictions are violated, the class is not buildable or runnable as a test and will display as an error."),(0,a.kt)("p",null,"It is advisable that the constructor not have any side effects, since NUnit may construct the object multiple times in the course of a session."),(0,a.kt)("h2",{id:"classic-test_class"},"Classic test_class"),(0,a.kt)("p",null,"The following examples shows how to register a test class with test",(0,a.kt)("em",{parentName:"p"},"class")," helper:"),(0,a.kt)("pre",null,(0,a.kt)("code",{parentName:"pre",className:"language-cpp"},"#include <xtd/tunit>\n\nusing namespace xtd::tunit;\n\nnamespace unit_tests {\n  class test_class_(test) {\n    // ...\n  };\n}\n\nauto main(int argc, char* argv[])->int {\n  return console_unit_test(argv, argc).run();\n}\n")),(0,a.kt)("h2",{id:"generic-test_class"},"Generic test_class"),(0,a.kt)("p",null,"For generic test_class actually no helper is provided."),(0,a.kt)("p",null,"The following example show how to register a generic test class without helper:"),(0,a.kt)("pre",null,(0,a.kt)("code",{parentName:"pre",className:"language-cpp"},"#include <xtd/tunit>\n\nusing namespace xtd::tunit;\n\nnamespace unit_tests {\n  template<typename T>\n  class test;\n\n  // Register generic test class with 'std:string' as generic parameter.\n  test_class_attribute<test<std::string>> test_class_string_attr {\"test<string>\"};\n\n  // Register generic test class with 'int' as generic parameter.\n  test_class_attribute<test<int>> test_class_int_attr {\"test<int>\"};\n\n  // Create new test fixture inherited test_class.\n  template<typename T>\n  class test : public test_class {\n  public:\n    void test_method_(test_case1) {\n    }\n  };\n}\n\nauto main(int argc, char* argv[])->int {\n  return console_unit_test(argv, argc).run();\n}\n")),(0,a.kt)("h2",{id:"inheritance"},"Inheritance"),(0,a.kt)("p",null,"The test_class may be applied to a base class and is inherited by any derived classes. This includes any abstract base class, so the well-known Abstract Fixture pattern may be implemented if desired."),(0,a.kt)("p",null,"The following code show how to register a derived class with helper :"),(0,a.kt)("pre",null,(0,a.kt)("code",{parentName:"pre",className:"language-cpp"},"#include <xtd/tunit>\n\nusing namespace xtd::tunit;\n\nnamespace unit_tests {\n  class base_test : public test_class {\n  public:\n    void test_method_(base_test_case1) {\n    }\n  };\n  \n  class test_class_from_(test, base_test) {\n  public:\n    void test_method_(test_case1) {\n    }\n  };\n}\n\nauto main(int argc, char* argv[])->int {\n  return console_unit_test(argv, argc).run();\n}\n")),(0,a.kt)("h2",{id:"see-also"},"See also"),(0,a.kt)("ul",null,(0,a.kt)("li",{parentName:"ul"},(0,a.kt)("a",{parentName:"li",href:"/docs/documentation/Guides/Overview/Tutorials/writing_applicaion_test"},"Writing test applications")),(0,a.kt)("li",{parentName:"ul"},(0,a.kt)("a",{parentName:"li",href:"/docs/documentation/Guides/Overview/Tutorials"},"Tutorials")),(0,a.kt)("li",{parentName:"ul"},(0,a.kt)("a",{parentName:"li",href:"/docs/documentation"},"Documentation"))))}d.isMDXComponent=!0}}]);