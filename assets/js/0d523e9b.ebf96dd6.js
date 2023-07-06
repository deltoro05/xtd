"use strict";(self.webpackChunkxtd=self.webpackChunkxtd||[]).push([[7],{91971:(e,t,a)=>{a.d(t,{Zo:()=>c,kt:()=>p});var r=a(76687);function s(e,t,a){return t in e?Object.defineProperty(e,t,{value:a,enumerable:!0,configurable:!0,writable:!0}):e[t]=a,e}function n(e,t){var a=Object.keys(e);if(Object.getOwnPropertySymbols){var r=Object.getOwnPropertySymbols(e);t&&(r=r.filter((function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable}))),a.push.apply(a,r)}return a}function o(e){for(var t=1;t<arguments.length;t++){var a=null!=arguments[t]?arguments[t]:{};t%2?n(Object(a),!0).forEach((function(t){s(e,t,a[t])})):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(a)):n(Object(a)).forEach((function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(a,t))}))}return e}function l(e,t){if(null==e)return{};var a,r,s=function(e,t){if(null==e)return{};var a,r,s={},n=Object.keys(e);for(r=0;r<n.length;r++)a=n[r],t.indexOf(a)>=0||(s[a]=e[a]);return s}(e,t);if(Object.getOwnPropertySymbols){var n=Object.getOwnPropertySymbols(e);for(r=0;r<n.length;r++)a=n[r],t.indexOf(a)>=0||Object.prototype.propertyIsEnumerable.call(e,a)&&(s[a]=e[a])}return s}var i=r.createContext({}),m=function(e){var t=r.useContext(i),a=t;return e&&(a="function"==typeof e?e(t):o(o({},t),e)),a},c=function(e){var t=m(e.components);return r.createElement(i.Provider,{value:t},e.children)},h="mdxType",d={inlineCode:"code",wrapper:function(e){var t=e.children;return r.createElement(r.Fragment,{},t)}},u=r.forwardRef((function(e,t){var a=e.components,s=e.mdxType,n=e.originalType,i=e.parentName,c=l(e,["components","mdxType","originalType","parentName"]),h=m(a),u=s,p=h["".concat(i,".").concat(u)]||h[u]||d[u]||n;return a?r.createElement(p,o(o({ref:t},c),{},{components:a})):r.createElement(p,o({ref:t},c))}));function p(e,t){var a=arguments,s=t&&t.mdxType;if("string"==typeof e||s){var n=a.length,o=new Array(n);o[0]=u;var l={};for(var i in t)hasOwnProperty.call(t,i)&&(l[i]=t[i]);l.originalType=e,l[h]="string"==typeof e?e:s,o[1]=l;for(var m=2;m<n;m++)o[m]=a[m];return r.createElement.apply(null,o)}return r.createElement.apply(null,a)}u.displayName="MDXCreateElement"},73341:(e,t,a)=>{a.r(t),a.d(t,{assets:()=>i,contentTitle:()=>o,default:()=>d,frontMatter:()=>n,metadata:()=>l,toc:()=>m});var r=a(855),s=(a(76687),a(91971));const n={},o="Style sheets overview",l={unversionedId:"documentation/Guides/xtd.forms/Style sheets/style_sheets_overview",id:"documentation/Guides/xtd.forms/Style sheets/style_sheets_overview",title:"Style sheets overview",description:"We will now see a few examples to get started with using xtd style sheets.",source:"@site/docs/documentation/Guides/xtd.forms/Style sheets/style_sheets_overview.md",sourceDirName:"documentation/Guides/xtd.forms/Style sheets",slug:"/documentation/Guides/xtd.forms/Style sheets/style_sheets_overview",permalink:"/xtd/docs/documentation/Guides/xtd.forms/Style sheets/style_sheets_overview",draft:!1,tags:[],version:"current",frontMatter:{},sidebar:"tutorialSidebar",previous:{title:"Style sheets box model",permalink:"/xtd/docs/documentation/Guides/xtd.forms/Style sheets/style_sheets_box_model"},next:{title:"Style sheets reference",permalink:"/xtd/docs/documentation/Guides/xtd.forms/Style sheets/style_sheets_reference"}},i={},m=[{value:"CSS usage",id:"css-usage",level:2},{value:"xtd css example",id:"xtd-css-example",level:3},{value:"Remarks",id:"remarks",level:3},{value:"Style sheet usage",id:"style-sheet-usage",level:2},{value:"Themes",id:"themes",level:2},{value:"Current Operating System / Desktop Environment",id:"current-operating-system--desktop-environment",level:2},{value:"Generic",id:"generic",level:2},{value:"Colors only",id:"colors-only",level:2},{value:"Remarks",id:"remarks-1",level:2}],c={toc:m},h="wrapper";function d(e){let{components:t,...a}=e;return(0,s.kt)(h,(0,r.Z)({},c,a,{components:t,mdxType:"MDXLayout"}),(0,s.kt)("h1",{id:"style-sheets-overview"},"Style sheets overview"),(0,s.kt)("p",null,"We will now see a few examples to get started with using xtd style sheets."),(0,s.kt)("h2",{id:"css-usage"},"CSS usage"),(0,s.kt)("p",null,"Follow the ",(0,s.kt)("a",{parentName:"p",href:"https://www.w3schools.com/css/default.asp"},"css tutorial")," to read or write CSS style sheets."),(0,s.kt)("p",null,"CSS is used to define styles for xtd controls."),(0,s.kt)("h3",{id:"xtd-css-example"},"xtd css example"),(0,s.kt)("p",null,"The following example shows part of the style sheet of a button control for standard pseudo state :"),(0,s.kt)("pre",null,(0,s.kt)("code",{parentName:"pre",className:"language-css"},"button {\n  margin: 0px 1px 0px 1px;\n  border-style: outset;\n  border-color: system-color(control-dark);\n  border-width: 1px;\n  border-radius: 5px;\n  background-image: linear-gradient(system-color(button-face), system-color(button-face));\n  padding: 1px 1px 1px 3px;\n  color: system-color(control-text);\n  text-align: middle center;\n  text-decoration: none;\n}\n")),(0,s.kt)("p",null,"The following example shows part of the style sheet of a button control for pressed pseudo state :"),(0,s.kt)("pre",null,(0,s.kt)("code",{parentName:"pre",className:"language-css"},"button:pressed {\n  background-image: linear-gradient(rgba(255, 255, 255, 93), rgba(255, 255, 255, 93));\n}\n")),(0,s.kt)("p",null,"It can be noticed that only the properties that differ with the standard pseudo state are expressed.\nThe other properties will be the same as those of the standard preudo state."),(0,s.kt)("h3",{id:"remarks"},"Remarks"),(0,s.kt)("p",null,"we can notice that the property is written like this :"),(0,s.kt)("pre",null,(0,s.kt)("code",{parentName:"pre",className:"language-css"},"  background-image: linear-gradient(system-color(button-face), system-color(button-face));\n")),(0,s.kt)("p",null,"when we could have simply written this:"),(0,s.kt)("pre",null,(0,s.kt)("code",{parentName:"pre",className:"language-css"},"  background-color: system-color(button-face);\n")),(0,s.kt)("p",null,"The difference between the two cases is that if you change the background color of the button by programming, in the first case, the button is not impacted while in the second case the button will take the color defined by programming.\nSo it's a design choice."),(0,s.kt)("p",null,"A background color can be replaced on the fly while ab ackground image cannot."),(0,s.kt)("p",null,"In the case of our example we don't want a change of color to change the appearance of the button because we can imagine that the color of the system button-face is semi-transparent."),(0,s.kt)("h2",{id:"style-sheet-usage"},"Style sheet usage"),(0,s.kt)("p",null,"coming soon..."),(0,s.kt)("h2",{id:"themes"},"Themes"),(0,s.kt)("p",null,"xtd has predifined themes for major operating system and desktop environment and also some specific themes."),(0,s.kt)("p",null,"Feel free to browse these themes for inspiration."),(0,s.kt)("h2",{id:"current-operating-system--desktop-environment"},"Current Operating System / Desktop Environment"),(0,s.kt)("ul",null,(0,s.kt)("li",{parentName:"ul"},(0,s.kt)("a",{parentName:"li",href:"https://github.com/gammasoft71/xtd/tree/master/themes/gnome_dark"},"gnome_dark")," contains GNOME dark theme."),(0,s.kt)("li",{parentName:"ul"},(0,s.kt)("a",{parentName:"li",href:"https://github.com/gammasoft71/xtd/tree/master/themes/gnome_light"},"gnome_light")," contains GNOME dark theme."),(0,s.kt)("li",{parentName:"ul"},(0,s.kt)("a",{parentName:"li",href:"https://github.com/gammasoft71/xtd/tree/master/themes/kde_dark"},"kde_dark")," contains KDE dark theme."),(0,s.kt)("li",{parentName:"ul"},(0,s.kt)("a",{parentName:"li",href:"https://github.com/gammasoft71/xtd/tree/master/themes/kde_light"},"kde_light")," contains KDE dark theme."),(0,s.kt)("li",{parentName:"ul"},(0,s.kt)("a",{parentName:"li",href:"https://github.com/gammasoft71/xtd/tree/master/themes/macos_dark"},"macos_dark")," contains macOS dark theme."),(0,s.kt)("li",{parentName:"ul"},(0,s.kt)("a",{parentName:"li",href:"https://github.com/gammasoft71/xtd/tree/master/themes/macos_dark"},"macos_light")," contains macOS light theme."),(0,s.kt)("li",{parentName:"ul"},(0,s.kt)("a",{parentName:"li",href:"https://github.com/gammasoft71/xtd/tree/master/themes/windows_dark"},"windows_dark")," contains Windows dark theme."),(0,s.kt)("li",{parentName:"ul"},(0,s.kt)("a",{parentName:"li",href:"https://github.com/gammasoft71/xtd/tree/master/themes/windows_light"},"windows_light")," contains Windows light theme.")),(0,s.kt)("h2",{id:"generic"},"Generic"),(0,s.kt)("ul",null,(0,s.kt)("li",{parentName:"ul"},(0,s.kt)("a",{parentName:"li",href:"https://github.com/gammasoft71/xtd/tree/master/themes/symbolic_dark"},"symbolic_dark")," contains Symbolic dark theme."),(0,s.kt)("li",{parentName:"ul"},(0,s.kt)("a",{parentName:"li",href:"https://github.com/gammasoft71/xtd/tree/master/themes/symbolic_light"},"symbolic_light")," contains Symbolic light theme."),(0,s.kt)("li",{parentName:"ul"},(0,s.kt)("a",{parentName:"li",href:"https://github.com/gammasoft71/xtd/tree/master/themes/xtd_dark"},"xtd_dark")," contains xtd dark theme."),(0,s.kt)("li",{parentName:"ul"},(0,s.kt)("a",{parentName:"li",href:"https://github.com/gammasoft71/xtd/tree/master/themes/xtd_light"},"xtd_light")," contains xtd light theme.")),(0,s.kt)("h2",{id:"colors-only"},"Colors only"),(0,s.kt)("ul",null,(0,s.kt)("li",{parentName:"ul"},(0,s.kt)("a",{parentName:"li",href:"https://github.com/gammasoft71/xtd/tree/master/themes/black"},"black")," contains black color theme."),(0,s.kt)("li",{parentName:"ul"},(0,s.kt)("a",{parentName:"li",href:"https://github.com/gammasoft71/xtd/tree/master/themes/blue"},"blue")," contains blue color theme."),(0,s.kt)("li",{parentName:"ul"},(0,s.kt)("a",{parentName:"li",href:"https://github.com/gammasoft71/xtd/tree/master/themes/dark"},"dark")," contains dark color theme."),(0,s.kt)("li",{parentName:"ul"},(0,s.kt)("a",{parentName:"li",href:"https://github.com/gammasoft71/xtd/tree/master/themes/green"},"green")," contains green color theme."),(0,s.kt)("li",{parentName:"ul"},(0,s.kt)("a",{parentName:"li",href:"https://github.com/gammasoft71/xtd/tree/master/themes/light"},"light")," contains light color theme."),(0,s.kt)("li",{parentName:"ul"},(0,s.kt)("a",{parentName:"li",href:"https://github.com/gammasoft71/xtd/tree/master/themes/red"},"red")," contains red color theme."),(0,s.kt)("li",{parentName:"ul"},(0,s.kt)("a",{parentName:"li",href:"https://github.com/gammasoft71/xtd/tree/master/themes/white"},"white")," contains white color theme.")),(0,s.kt)("h2",{id:"remarks-1"},"Remarks"),(0,s.kt)("p",null,"The style sheet for each control has been split in several files for more clarity. But we could have put them in one file.\nxtd browses the whole folder and reads all files with the .css extension."),(0,s.kt)("h1",{id:"see-also"},"See also"),(0,s.kt)("p",null,"\u200b"),(0,s.kt)("ul",null,(0,s.kt)("li",{parentName:"ul"},(0,s.kt)("a",{parentName:"li",href:"/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_reference"},"Style sheets reference")),(0,s.kt)("li",{parentName:"ul"},(0,s.kt)("a",{parentName:"li",href:"/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_box_model"},"Box model")),(0,s.kt)("li",{parentName:"ul"},(0,s.kt)("a",{parentName:"li",href:"/docs/documentation/Guides"},"Guides")),(0,s.kt)("li",{parentName:"ul"},(0,s.kt)("a",{parentName:"li",href:"/docs/documentation"},"Documentation"))))}d.isMDXComponent=!0}}]);