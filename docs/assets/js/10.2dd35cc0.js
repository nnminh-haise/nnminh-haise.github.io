(window.webpackJsonp=window.webpackJsonp||[]).push([[10],{280:function(t,a,s){"use strict";s.r(a);var i=s(13),n=Object(i.a)({},(function(){var t=this,a=t._self._c;return a("ContentSlotsDistributor",{attrs:{"slot-key":t.$parent.slotKey}},[a("h1",{attrs:{id:"tong-day"}},[t._v("Tổng dãy")]),t._v(" "),a("p",[t._v("Cho một dãy "),a("span",{staticClass:"katex"},[a("span",{staticClass:"katex-mathml"},[a("math",[a("semantics",[a("mrow",[a("mi",[t._v("A")])],1),a("annotation",{attrs:{encoding:"application/x-tex"}},[t._v("A")])],1)],1)],1),a("span",{staticClass:"katex-html",attrs:{"aria-hidden":"true"}},[a("span",{staticClass:"strut",staticStyle:{height:"0.68333em"}}),a("span",{staticClass:"strut bottom",staticStyle:{height:"0.68333em","vertical-align":"0em"}}),a("span",{staticClass:"base textstyle uncramped"},[a("span",{staticClass:"mord mathit"},[t._v("A")])])])]),t._v(" gồm "),a("span",{staticClass:"katex"},[a("span",{staticClass:"katex-mathml"},[a("math",[a("semantics",[a("mrow",[a("mi",[t._v("n")])],1),a("annotation",{attrs:{encoding:"application/x-tex"}},[t._v("n")])],1)],1)],1),a("span",{staticClass:"katex-html",attrs:{"aria-hidden":"true"}},[a("span",{staticClass:"strut",staticStyle:{height:"0.43056em"}}),a("span",{staticClass:"strut bottom",staticStyle:{height:"0.43056em","vertical-align":"0em"}}),a("span",{staticClass:"base textstyle uncramped"},[a("span",{staticClass:"mord mathit"},[t._v("n")])])])]),t._v(" số nguyên dương a_1, a_2, a_3, \\dots, a_n và một số nguyên dương "),a("span",{staticClass:"katex"},[a("span",{staticClass:"katex-mathml"},[a("math",[a("semantics",[a("mrow",[a("mi",[t._v("k")])],1),a("annotation",{attrs:{encoding:"application/x-tex"}},[t._v("k")])],1)],1)],1),a("span",{staticClass:"katex-html",attrs:{"aria-hidden":"true"}},[a("span",{staticClass:"strut",staticStyle:{height:"0.69444em"}}),a("span",{staticClass:"strut bottom",staticStyle:{height:"0.69444em","vertical-align":"0em"}}),a("span",{staticClass:"base textstyle uncramped"},[a("span",{staticClass:"mord mathit",staticStyle:{"margin-right":"0.03148em"}},[t._v("k")])])])]),t._v(".")]),t._v(" "),a("p",[a("em",[a("strong",[t._v("Yêu cầu:")])]),t._v(" Tính tổng các phần tử trong dãy và đưa ra kết quả là phần dư của tổng vừa tìm cho "),a("span",{staticClass:"katex"},[a("span",{staticClass:"katex-mathml"},[a("math",[a("semantics",[a("mrow",[a("mi",[t._v("k")])],1),a("annotation",{attrs:{encoding:"application/x-tex"}},[t._v("k")])],1)],1)],1),a("span",{staticClass:"katex-html",attrs:{"aria-hidden":"true"}},[a("span",{staticClass:"strut",staticStyle:{height:"0.69444em"}}),a("span",{staticClass:"strut bottom",staticStyle:{height:"0.69444em","vertical-align":"0em"}}),a("span",{staticClass:"base textstyle uncramped"},[a("span",{staticClass:"mord mathit",staticStyle:{"margin-right":"0.03148em"}},[t._v("k")])])])]),t._v(".")]),t._v(" "),a("h2",{attrs:{id:"du-lieu-vao"}},[t._v("Dữ liệu vào")]),t._v(" "),a("ul",[a("li",[t._v("Dòng đầu tiên gồm hai số nguyên dương "),a("span",{staticClass:"katex"},[a("span",{staticClass:"katex-mathml"},[a("math",[a("semantics",[a("mrow",[a("mi",[t._v("n")]),a("mspace",{attrs:{width:"0.277778em"}}),a("mo",[t._v("(")]),a("mn",[t._v("1")]),a("mo",[t._v("≤")]),a("mi",[t._v("n")]),a("mo",[t._v("≤")]),a("mn",[t._v("1")]),a("mn",[t._v("0")]),a("mn",[t._v("0")]),a("mn",[t._v("0")]),a("mo",[t._v(")")])],1),a("annotation",{attrs:{encoding:"application/x-tex"}},[t._v("n \\; (1 \\le n \\le 1000)")])],1)],1)],1),a("span",{staticClass:"katex-html",attrs:{"aria-hidden":"true"}},[a("span",{staticClass:"strut",staticStyle:{height:"0.75em"}}),a("span",{staticClass:"strut bottom",staticStyle:{height:"1em","vertical-align":"-0.25em"}}),a("span",{staticClass:"base textstyle uncramped"},[a("span",{staticClass:"mord mathit"},[t._v("n")]),a("span",{staticClass:"mord mspace thickspace"}),a("span",{staticClass:"mopen"},[t._v("(")]),a("span",{staticClass:"mord mathrm"},[t._v("1")]),a("span",{staticClass:"mrel"},[t._v("≤")]),a("span",{staticClass:"mord mathit"},[t._v("n")]),a("span",{staticClass:"mrel"},[t._v("≤")]),a("span",{staticClass:"mord mathrm"},[t._v("1")]),a("span",{staticClass:"mord mathrm"},[t._v("0")]),a("span",{staticClass:"mord mathrm"},[t._v("0")]),a("span",{staticClass:"mord mathrm"},[t._v("0")]),a("span",{staticClass:"mclose"},[t._v(")")])])])]),t._v(" và "),a("span",{staticClass:"katex"},[a("span",{staticClass:"katex-mathml"},[a("math",[a("semantics",[a("mrow",[a("mi",[t._v("k")]),a("mspace",{attrs:{width:"0.277778em"}}),a("mo",[t._v("(")]),a("mn",[t._v("1")]),a("mo",[t._v("≤")]),a("mi",[t._v("n")]),a("mo",[t._v("≤")]),a("mn",[t._v("1")]),a("mn",[t._v("0")]),a("mn",[t._v("0")]),a("mn",[t._v("0")]),a("mo",[t._v(")")])],1),a("annotation",{attrs:{encoding:"application/x-tex"}},[t._v("k \\; (1 \\le n \\le 1000)")])],1)],1)],1),a("span",{staticClass:"katex-html",attrs:{"aria-hidden":"true"}},[a("span",{staticClass:"strut",staticStyle:{height:"0.75em"}}),a("span",{staticClass:"strut bottom",staticStyle:{height:"1em","vertical-align":"-0.25em"}}),a("span",{staticClass:"base textstyle uncramped"},[a("span",{staticClass:"mord mathit",staticStyle:{"margin-right":"0.03148em"}},[t._v("k")]),a("span",{staticClass:"mord mspace thickspace"}),a("span",{staticClass:"mopen"},[t._v("(")]),a("span",{staticClass:"mord mathrm"},[t._v("1")]),a("span",{staticClass:"mrel"},[t._v("≤")]),a("span",{staticClass:"mord mathit"},[t._v("n")]),a("span",{staticClass:"mrel"},[t._v("≤")]),a("span",{staticClass:"mord mathrm"},[t._v("1")]),a("span",{staticClass:"mord mathrm"},[t._v("0")]),a("span",{staticClass:"mord mathrm"},[t._v("0")]),a("span",{staticClass:"mord mathrm"},[t._v("0")]),a("span",{staticClass:"mclose"},[t._v(")")])])])]),t._v(".")]),t._v(" "),a("li",[t._v("Dòng thứ hai gồm "),a("span",{staticClass:"katex"},[a("span",{staticClass:"katex-mathml"},[a("math",[a("semantics",[a("mrow",[a("mi",[t._v("n")])],1),a("annotation",{attrs:{encoding:"application/x-tex"}},[t._v("n")])],1)],1)],1),a("span",{staticClass:"katex-html",attrs:{"aria-hidden":"true"}},[a("span",{staticClass:"strut",staticStyle:{height:"0.43056em"}}),a("span",{staticClass:"strut bottom",staticStyle:{height:"0.43056em","vertical-align":"0em"}}),a("span",{staticClass:"base textstyle uncramped"},[a("span",{staticClass:"mord mathit"},[t._v("n")])])])]),t._v(" số nguyên a_1, a_2, a_3, \\dots, a_n \\; (1 \\le a_i \\le 1000).")])]),t._v(" "),a("h2",{attrs:{id:"du-lieu-ra"}},[t._v("Dữ liệu ra")]),t._v(" "),a("ul",[a("li",[t._v("Một số nguyên duy nhất là phần dư của phép chia tổng các phần tử trong dãy "),a("span",{staticClass:"katex"},[a("span",{staticClass:"katex-mathml"},[a("math",[a("semantics",[a("mrow",[a("mi",[t._v("A")])],1),a("annotation",{attrs:{encoding:"application/x-tex"}},[t._v("A")])],1)],1)],1),a("span",{staticClass:"katex-html",attrs:{"aria-hidden":"true"}},[a("span",{staticClass:"strut",staticStyle:{height:"0.68333em"}}),a("span",{staticClass:"strut bottom",staticStyle:{height:"0.68333em","vertical-align":"0em"}}),a("span",{staticClass:"base textstyle uncramped"},[a("span",{staticClass:"mord mathit"},[t._v("A")])])])]),t._v(" với số nguyên dương "),a("span",{staticClass:"katex"},[a("span",{staticClass:"katex-mathml"},[a("math",[a("semantics",[a("mrow",[a("mi",[t._v("k")])],1),a("annotation",{attrs:{encoding:"application/x-tex"}},[t._v("k")])],1)],1)],1),a("span",{staticClass:"katex-html",attrs:{"aria-hidden":"true"}},[a("span",{staticClass:"strut",staticStyle:{height:"0.69444em"}}),a("span",{staticClass:"strut bottom",staticStyle:{height:"0.69444em","vertical-align":"0em"}}),a("span",{staticClass:"base textstyle uncramped"},[a("span",{staticClass:"mord mathit",staticStyle:{"margin-right":"0.03148em"}},[t._v("k")])])])]),t._v(".")])]),t._v(" "),a("h2",{attrs:{id:"vi-du"}},[t._v("Ví dụ")]),t._v(" "),a("p",[a("em",[a("strong",[t._v("Input:")])])]),t._v(" "),a("div",{staticClass:"language- line-numbers-mode"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("5 4\n1 2 3 4 5\n")])]),t._v(" "),a("div",{staticClass:"line-numbers-wrapper"},[a("span",{staticClass:"line-number"},[t._v("1")]),a("br"),a("span",{staticClass:"line-number"},[t._v("2")]),a("br")])]),a("p",[a("em",[a("strong",[t._v("Output:")])])]),t._v(" "),a("div",{staticClass:"language- line-numbers-mode"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("3\n")])]),t._v(" "),a("div",{staticClass:"line-numbers-wrapper"},[a("span",{staticClass:"line-number"},[t._v("1")]),a("br")])]),a("p",[a("em",[a("strong",[t._v("Explanation:")])])]),t._v(" "),a("p",[t._v("Ta có: \\sum\\limits_{i = 1}^{5}i = 15 \\to 15 \\mod 4 = 3.")])])}),[],!1,null,null,null);a.default=n.exports}}]);