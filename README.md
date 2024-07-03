# metamod-source-plugin
Template of the [Metamod:Source](https://github.com/alliedmodders/metamod-source) plugin without using the HL2SDK

## Required packages
- [metamod-source](https://alliedmodders-meson.github.io/wrapdb/)

## Packaging of the plugin content
- `package/files` - content that will be installed inside the `addons/<name>` directory.
- `package/.vdf.in` - configuration file that will generate the "Metamod Plugin" configuration inside the `addons/metamod` directory.
