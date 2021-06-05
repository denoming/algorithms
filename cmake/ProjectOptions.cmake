include(FeatureSummary)

option(ALG_ENABLE_TESTS "Enable testing" ON)
add_feature_info(ALG_ENABLE_TESTS ALG_ENABLE_TESTS "Build project with tests")

feature_summary(WHAT ALL)
