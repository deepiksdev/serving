# Description: Tensorflow Serving examples.

package(
    default_visibility = ["//tensorflow_serving:internal"],
    features = ["no_layering_check"],
)

licenses(["notice"])  # Apache 2.0

exports_files(["LICENSE"])

load("//tensorflow_serving:serving.bzl", "serving_proto_library")

filegroup(
    name = "all_files",
    srcs = glob(
        ["**/*"],
        exclude = [
            "**/METADATA",
            "**/OWNERS",
        ],
    ),
)


cc_binary(
    name = "inception_client_cc",
    srcs = [
        "inception_client.cc",
    ],
    deps = [
        "//tensorflow_serving/apis:prediction_service_proto",
        "@grpc//:grpc++",
        "@org_tensorflow//tensorflow/core:framework",
        "@protobuf//:protobuf_lite",
        "@curl//:curl",
    ],
)
