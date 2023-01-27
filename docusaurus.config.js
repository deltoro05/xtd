// @ts-check
// Note: type annotations allow type checking and IDEs autocompletion

const lightCodeTheme = require('prism-react-renderer/themes/github');
const darkCodeTheme = require('prism-react-renderer/themes/dracula');

/** @type {import('@docusaurus/types').Config} */
const config = {
  //title: 'xtd',
  //tagline: 'xtd (pronounced "extend") is a modern C++17/20 framework to create console, GUI and unit test applications on Microsoft Windows, macOS, Linux, iOS and android (*).',
  title: ' ',
  tagline: ' ',
  url: 'https://gammasoft71.github.io',
  baseUrl: '/xtd/',
  onBrokenLinks: 'throw',
  onBrokenMarkdownLinks: 'warn',
  favicon: 'pictures/favicon.ico',

  // GitHub pages deployment config.
  // If you aren't using GitHub pages, you don't need these.
  organizationName: 'gammasoft71', // Usually your GitHub org/user name.
  projectName: 'xtd', // Usually your repo name.
  trailingSlash: false,

  // Even if you don't use internalization, you can use this field to set useful
  // metadata like html lang. For example, if your site is Chinese, you may want
  // to replace "en" with "zh-Hans".
  i18n: {
    defaultLocale: 'en',
    locales: ['en'],
  },

  presets: [
    [
      'classic',
      /** @type {import('@docusaurus/preset-classic').Options} */
      ({
        docs: {
          sidebarPath: require.resolve('./sidebars.js'),
          // Please change this to your repo.
          // Remove this to remove the "edit this page" links.
          //editUrl: 'https://github.com/gammasoft71/xtd/tree/docs',
        },
        blog: false,
        theme: {
          customCss: require.resolve('./src/css/custom.css'),
        },
      }),
    ],
  ],

  themeConfig:
    /** @type {import('@docusaurus/preset-classic').ThemeConfig} */
    ({
      navbar: {
        title: 'xtd',
        logo: {
          alt: 'My Site Logo',
          src: 'pictures/logo.png',
        },
        items: [
          {
            type: 'doc',
            docId: 'news',
            position: 'left',
            label: 'News',
          },
          {
            type: 'doc',
            docId: 'gallery',
            position: 'left',
            label: 'Gallery',
          },
          {
            type: 'doc',
            docId: 'examples',
            position: 'left',
            label: 'Examples',
          },
          {
            type: 'doc',
            docId: 'downloads',
            position: 'left',
            label: 'Downloads',
          },
          {
            type: 'doc',
            docId: 'documentation/documentation',
            position: 'left',
            label: 'Documentation',
          },
          {
            type: 'doc',
            docId: 'support/support',
            position: 'left',
            label: 'Support',
          },
          {
            href: 'https://github.com/gammasoft71/xtd',
            label: 'Sources',
            position: 'left',
          },
          {
            href: 'https://sourceforge.net/projects/xtdpro/',
            label: 'Project',
            position: 'left',
          },
          {
            href: 'https://gammasoft71.wixsite.com/gammasoft/',
            label: 'Gammasoft',
            position: 'left',
          },
        ],
      },
      footer: {
        style: 'dark',
        links: [
          {
            html: '<a href="https://github.com/gammasoft71/xtd"><img src=pictures/github32.png></a>',
          },
          {
            html: '<a href="https://sourceforge.net/u/gammasoft71"><img src=pictures/sourceforge32.png></a>',
          },
          {
            html: '<a href="https://www.facebook.com/gammasoft71"><img src=pictures/facebook32.png></a>',
          },
          {
            html: '<a href="hhttps://twitter.com/gammasoft71"><img src=pictures/twitter32.png></a>',
          },
          {
            html: '<a href="https://discordapp.com/users/gammasoft#9288"><img src=pictures/discord32.png></a>',
          },
        ],
        copyright: `© ${new Date().getFullYear()} Gammasoft. Built with Docusaurus.`,
      },
      prism: {
        theme: lightCodeTheme,
        darkTheme: darkCodeTheme,
      },
    }),
};

module.exports = config;
