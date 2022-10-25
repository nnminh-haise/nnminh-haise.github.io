module.exports = {
    title: 'Cậu bạn tên Minh',
    description: 'Chào cậu, mình tên là Minh và đây là nơi mình chia sẽ kiến thức, suy nghĩ của mình đến với mọi người.',
    head: [
        ['link', { rel: 'icon', href: '/logo.png' }],
        ['link', { rel: 'stylesheet', href: 'https://cdnjs.cloudflare.com/ajax/libs/github-markdown-css/5.1.0/github-markdown.css'}],
        ['link', { rel: 'stylesheet', href: 'https://cdnjs.cloudflare.com/ajax/libs/KaTeX/0.5.1/katex.min.css'}],
    ],
    host: 'localhost', 
    port: 3000,
    dest: 'docs',
    themeConfig: {
        nav: [
            { text: 'Home', link: '/' },
            { text: 'About', link: '/About/'},
            { text: 'Facebook', link: 'https://www.facebook.com/nnminh.haise/'},
            { text: 'Github', link: 'https://github.com/nnminh-haise'},
        ],
        sidebar: 'auto',
        displayAllHeaders: true,
    },
    markdown: {
        lineNumbers: true,
        anchor: { permalink: false },
        extendMarkdown: md => {
            md.use(require("markdown-it-katex"));
        },
    },
};