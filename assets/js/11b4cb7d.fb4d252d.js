"use strict";(self.webpackChunkxtd=self.webpackChunkxtd||[]).push([[1009],{91971:(e,t,a)=>{a.d(t,{Zo:()=>c,kt:()=>_});var r=a(76687);function n(e,t,a){return t in e?Object.defineProperty(e,t,{value:a,enumerable:!0,configurable:!0,writable:!0}):e[t]=a,e}function o(e,t){var a=Object.keys(e);if(Object.getOwnPropertySymbols){var r=Object.getOwnPropertySymbols(e);t&&(r=r.filter((function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable}))),a.push.apply(a,r)}return a}function i(e){for(var t=1;t<arguments.length;t++){var a=null!=arguments[t]?arguments[t]:{};t%2?o(Object(a),!0).forEach((function(t){n(e,t,a[t])})):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(a)):o(Object(a)).forEach((function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(a,t))}))}return e}function s(e,t){if(null==e)return{};var a,r,n=function(e,t){if(null==e)return{};var a,r,n={},o=Object.keys(e);for(r=0;r<o.length;r++)a=o[r],t.indexOf(a)>=0||(n[a]=e[a]);return n}(e,t);if(Object.getOwnPropertySymbols){var o=Object.getOwnPropertySymbols(e);for(r=0;r<o.length;r++)a=o[r],t.indexOf(a)>=0||Object.prototype.propertyIsEnumerable.call(e,a)&&(n[a]=e[a])}return n}var d=r.createContext({}),l=function(e){var t=r.useContext(d),a=t;return e&&(a="function"==typeof e?e(t):i(i({},t),e)),a},c=function(e){var t=l(e.components);return r.createElement(d.Provider,{value:t},e.children)},m="mdxType",u={inlineCode:"code",wrapper:function(e){var t=e.children;return r.createElement(r.Fragment,{},t)}},p=r.forwardRef((function(e,t){var a=e.components,n=e.mdxType,o=e.originalType,d=e.parentName,c=s(e,["components","mdxType","originalType","parentName"]),m=l(a),p=n,_=m["".concat(d,".").concat(p)]||m[p]||u[p]||o;return a?r.createElement(_,i(i({ref:t},c),{},{components:a})):r.createElement(_,i({ref:t},c))}));function _(e,t){var a=arguments,n=t&&t.mdxType;if("string"==typeof e||n){var o=a.length,i=new Array(o);i[0]=p;var s={};for(var d in t)hasOwnProperty.call(t,d)&&(s[d]=t[d]);s.originalType=e,s[m]="string"==typeof e?e:n,i[1]=s;for(var l=2;l<o;l++)i[l]=a[l];return r.createElement.apply(null,i)}return r.createElement.apply(null,a)}p.displayName="MDXCreateElement"},21666:(e,t,a)=>{a.r(t),a.d(t,{assets:()=>d,contentTitle:()=>i,default:()=>u,frontMatter:()=>o,metadata:()=>s,toc:()=>l});var r=a(855),n=(a(76687),a(91971));const o={},i="How to: Read and Write to a Newly Created Data File",s={unversionedId:"documentation/Guides/xtd.core/Common I:O tasks/How-tos/read_and_write_to_a_newly_created_data_file",id:"documentation/Guides/xtd.core/Common I:O tasks/How-tos/read_and_write_to_a_newly_created_data_file",title:"How to: Read and Write to a Newly Created Data File",description:"The xtd::binary_reader classes are used for writing and reading data other than character strings.",source:"@site/docs/documentation/Guides/xtd.core/Common I:O tasks/How-tos/read_and_write_to_a_newly_created_data_file.md",sourceDirName:"documentation/Guides/xtd.core/Common I:O tasks/How-tos",slug:"/documentation/Guides/xtd.core/Common I:O tasks/How-tos/read_and_write_to_a_newly_created_data_file",permalink:"/xtd/docs/documentation/Guides/xtd.core/Common I:O tasks/How-tos/read_and_write_to_a_newly_created_data_file",draft:!1,tags:[],version:"current",frontMatter:{},sidebar:"tutorialSidebar",previous:{title:"How to: Open and Append to a Log File",permalink:"/xtd/docs/documentation/Guides/xtd.core/Common I:O tasks/How-tos/open_and_append_to_a_log_file"},next:{title:"How to: Read Text from a File",permalink:"/xtd/docs/documentation/Guides/xtd.core/Common I:O tasks/How-tos/read_text_from_a_file"}},d={},l=[{value:"Example",id:"example",level:2},{value:"See also",id:"see-also",level:2}],c={toc:l},m="wrapper";function u(e){let{components:t,...a}=e;return(0,n.kt)(m,(0,r.Z)({},c,a,{components:t,mdxType:"MDXLayout"}),(0,n.kt)("h1",{id:"how-to-read-and-write-to-a-newly-created-data-file"},"How to: Read and Write to a Newly Created Data File"),(0,n.kt)("p",null,"The ",(0,n.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1binary__writer.html"},"xtd::io::binary_writer")," and ",(0,n.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1binary__reader.html"},"xtd::io::binary_reader")," classes are used for writing and reading data other than character strings.\nThe following example shows how to create an empty file stream, write data to it, and read data from it."),(0,n.kt)("p",null,"The example creates a data file called ",(0,n.kt)("em",{parentName:"p"},"test.data")," in the current directory, creates the associated ",(0,n.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1binary__writer.html"},"binary_writer")," and ",(0,n.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1binary__reader.html"},"binary_reader")," objects, and uses the ",(0,n.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1binary__writer.html"},"binary_writer")," object to write the integers 0 through 10 to ",(0,n.kt)("em",{parentName:"p"},"test.data"),", which leaves the file pointer at the end of the file.\nThe ",(0,n.kt)("a",{parentName:"p",href:"https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1binary__reader.html"},"binary_reader")," object then sets the file pointer back to the origin and reads out the specified content."),(0,n.kt)("h2",{id:"example"},"Example"),(0,n.kt)("pre",null,(0,n.kt)("code",{parentName:"pre",className:"language-cpp"},'#include <fstream>\n#include <xtd/xtd>\n\nusing namespace std;\nusing namespace xtd;\nusing namespace xtd::io;\n\nclass program {\nprivate:\n  inline static const ustring FILE_NAME = "test.data";\n  \npublic:\n  static auto main() {\n    if (file::exists(FILE_NAME)) {\n      console::write_line("{} already exists!", FILE_NAME);\n      return;\n    }\n    \n    using_ (ofstream fs(FILE_NAME, ios::binary | ios::out)) {\n      using_ (binary_writer w(fs)) {\n        for (int i = 0; i < 11; i++) {\n          w.write(i);\n        }\n      }\n    }\n    \n    using_ (ifstream fs(FILE_NAME, ios::binary | ios::in)) {\n      using_ (binary_reader r(fs)) {\n        for (int i = 0; i < 11; i++) {\n          console::write_line(r.read_int32());\n        }\n      }\n    }\n  }\n};\n\nstartup_(program);\n\n// The example creates a file named "Test.data" and writes the integers 0 through 10 to it in binary format.\n// It then writes the contents of Test.data to the console with each integer on a separate line.\n')),(0,n.kt)("h2",{id:"see-also"},"See also"),(0,n.kt)("ul",null,(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("a",{parentName:"li",href:"/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks"},"Common I/O Tasks")),(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("a",{parentName:"li",href:"/docs/documentation/Guides/Overview/Tutorials"},"Tutorials")),(0,n.kt)("li",{parentName:"ul"},(0,n.kt)("a",{parentName:"li",href:"/docs/documentation"},"Documentation"))))}u.isMDXComponent=!0}}]);