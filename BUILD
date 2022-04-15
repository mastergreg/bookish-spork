cc_library(
    name = "main",
    srcs = [
        "book.cpp",
        "inventory.cpp",
        "library.cpp",
        "shop.cpp",
    ],
    hdrs = [
        "book.hpp",
        "inventory.hpp",
        "library.hpp",
        "main.hpp",
        "shop.hpp",
    ],
)

cc_test(
    name = "test",
    size = "small",
    srcs = [
        "test_inventory.cpp",
        "test_library.cpp",
        "test_shop.cpp",
    ],
    deps = [
        "//:main",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "app",
    srcs = ["app.cpp"],
    deps = ["//:main"],
)
