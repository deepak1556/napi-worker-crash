{
  'targets': [
    {
      'target_name': 'Test',
      'cflags!': [ '-fno-exceptions' ],
      'cflags_cc!': [ '-fno-exceptions' ],
      'xcode_settings': {
        'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
      },
      'msvs_settings': {
        'VCCLCompilerTool': { 'ExceptionHandling': 1 },
      },
      'defines': [ 'NAPI_CPP_EXCEPTIONS' ],
      'include_dirs': ["<!(node -p \"require('node-addon-api').include_dir\")"],
      'sources': [
        'src/async.cc',
        'src/main.cc',
      ],
    }
  ]
}
