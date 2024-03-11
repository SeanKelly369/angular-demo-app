const webpack = require('@nativescript/webpack')
const { merge } = require('webpack-merge')

module.exports = (env) => {
  if (env.unitTesting == true) {
    webpack.chainWebpack((config) => {
      config.plugin('AngularWebpackPlugin').tap((args) => {
        args[0].tsconfig = './tsconfig.spec.json'
        return args
      })
      // keep the test runner open
      config.plugin('DefinePlugin').tap((args) => {
        args[0] = merge(args[0], {
          __TEST_RUNNER_STAY_OPEN__: true,
        })
        return args
      })
    })
  }
}