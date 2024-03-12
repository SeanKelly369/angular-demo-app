const webpack = require("@nativescript/webpack");

module.exports = (env) => {
	webpack.init(env);

	// Learn how to customize:
	// https://docs.nativescript.org/webpack

  // TODO: work out why this FAILS
  // if (env.unitTesting == true) {
  //   webpack.chainWebpack((config) => {
  //     config.plugin('AngularWebpackPlugin').tap((args) => {
  //       args[0].tsconfig = './tsconfig.spec.json'
  //       return args
  //     })
  //     // keep the test runner open
  //     config.plugin('DefinePlugin').tap((args) => {
  //       args[0] = merge(args[0], {
  //         __TEST_RUNNER_STAY_OPEN__: true,
  //       })
  //       return args
  //     })
  //   })
  // }

	return webpack.resolveConfig();
};
