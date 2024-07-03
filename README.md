# metamod-source-plugin
Plugin template for [Metamod:Source](https://github.com/alliedmodders/metamod-source) without using Source SDK

## Required packages
- [metamod-source](https://alliedmodders-meson.github.io/wrapdb/)

## Packaging of the plugin content
- `package/files` - content that will be installed inside the `addons/<plugin_name>` directory.
- `package/.vdf.in` - configuration file that will generate the Metamod plugin config inside the `addons/metamod` directory.
