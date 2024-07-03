project('metamod-source-plugin', 'c', 'cpp',
  meson_version : '>=1.4.1',
  default_options : {
    'cpp_std' : 'c++17',
    'b_ndebug' : 'if-release'
  }
)

#
# global settings
#

args = []

cpp = meson.get_compiler('cpp')
cpp_as = cpp.get_argument_syntax()

if cpp_as == 'gcc'
  args += [
    '-pipe',
    '-msse',
    '-mfpmath=sse',
    '-fno-strict-aliasing',
    '-fno-omit-frame-pointer'
  ]
elif cpp_as == 'msvc'
  args += ['/Oy-']
endif

if get_option('debug')
  args += ['-DDEBUG']
endif

add_project_arguments(args, language : ['c', 'cpp'])

#
# build & install
#

plugin_name = get_option('name')

if plugin_name == ''
  plugin_name = meson.project_name()
endif

plugin_alias = get_option('alias')

if plugin_alias == ''
  plugin_alias = plugin_name
endif

package_dir = meson.current_source_dir() / 'package'
packages_dir = meson.current_build_dir() / 'packages'

install_dir = packages_dir / '@0@.@1@.@2@.@3@'.format(
  plugin_name,
  host_machine.system(),
  host_machine.cpu_family(),
  get_option('buildtype')
)

# build plugin
src = []
inc = []

subdir('src')

args = ['-DMETA_NO_HL2SDK']

shared_module(plugin_name, src,
  c_args : args,
  cpp_args : args,
  dependencies : dependency('metamod-source'),
  include_directories : inc,
  gnu_symbol_visibility : 'inlineshidden',
  name_prefix : '',
  install : true,
  install_dir : install_dir / 'addons' / plugin_name / 'bin'
)

# generate vdf
configure_file(
  input : package_dir / '.vdf.in',
  output : plugin_name + '.vdf',
  configuration : {
    'file' : 'addons' / plugin_name / 'bin' / plugin_name,
    'alias' : plugin_alias
  },
  install : true,
  install_dir : install_dir / 'addons' / 'metamod'
)

# copy files
install_subdir(package_dir / 'files',
  exclude_files : [
    '.gitkeep'
  ],
  strip_directory : true,
  install_dir : install_dir / 'addons' / plugin_name
)