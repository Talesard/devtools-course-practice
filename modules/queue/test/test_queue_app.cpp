// Copyright 2021 Evgeniy Napylov

#include <gtest/gtest.h>

#include "include/queue_app.h"

TEST(test_queue_app, can_create) {
    ASSERT_NO_THROW(QueueApp());
}

TEST(test_queue_app, empty_args) {
    const int argc = 1;
    std::vector<const char*> argv = { "app"};
    QueueApp app;

    ASSERT_NO_THROW(app(argc, argv.data()));
}

TEST(test_queue_app, invalid_args) {
    const int argc = 2;
    std::vector<const char*> argv = { "app", "pepega" };
    QueueApp app;

    std::string res = app(argc, argv.data());
    std::string correct = "invalid arg";

    ASSERT_EQ(correct, res);
}

TEST(test_queue_app, append) {
    const int argc = 4;
    std::vector<const char*> argv = { "app", "append", "11.5", "get_first" };
    QueueApp app;

    double res = stod(app(argc, argv.data()));
    double correct = stod(std::string("11.5"));

    ASSERT_EQ(correct, res);
}

TEST(test_queue_app, append_invalid) {
    const int argc = 3;
    std::vector<const char*> argv = { "app", "append", "pepega" };
    QueueApp app;

    std::string res = app(argc, argv.data());
    std::string correct = "Wrong number format!";

    ASSERT_EQ(correct, res);
}

TEST(test_queue_app, is_empty_true) {
    const int argc = 2;
    std::vector<const char*> argv = { "app", "is_empty" };
    QueueApp app;

    std::string res = app(argc, argv.data());
    std::string correct = "1\n";

    ASSERT_EQ(correct, res);
}

TEST(test_queue_app, is_empty_false) {
    const int argc = 4;
    std::vector<const char*> argv = { "app", "append", "55", "is_empty" };
    QueueApp app;

    std::string res = app(argc, argv.data());
    std::string correct = "0\n";

    ASSERT_EQ(correct, res);
}

TEST(test_queue_app, get_first) {
    const int argc = 4;
    std::vector<const char*> argv = { "app", "append", "55.1", "get_first" };
    QueueApp app;

    double res = stod(app(argc, argv.data()));
    double correct = stod(std::string("55.1"));

    ASSERT_EQ(correct, res);
}

TEST(test_queue_app, rm_first) {
    const int argc = 7;
    std::vector<const char*> argv = { "app", "append", "55.1", "append", "66.2",
                                    "rm_first", "get_first" };
    QueueApp app;

    double res = stod(app(argc, argv.data()));
    double correct = stod(std::string("66.2"));

    ASSERT_EQ(correct, res);
}

TEST(test_queue_app, get_last) {
    const int argc = 6;
    std::vector<const char*> argv = { "app", "append", "55.1",
                                "append", "66.2", "get_last" };
    QueueApp app;

    double res = stod(app(argc, argv.data()));
    double correct = stod(std::string("66.2"));

    ASSERT_EQ(correct, res);
}

TEST(test_queue_app, get_size) {
    const int argc = 6;
    std::vector<const char*> argv = { "app", "append", "55.1",
                                "append", "66.2", "get_size" };
    QueueApp app;

    int res = stoi(app(argc, argv.data()));
    int correct = 2;

    ASSERT_EQ(correct, res);
}

TEST(test_queue_app, get_all) {
    const int argc = 6;
    std::vector<const char*> argv = { "app", "append", "55.1", "append",
                                                    "66.2", "get_all" };
    QueueApp app;

    std::string res = app(argc, argv.data());
    std::string correct = "55.100000 66.200000 \n";  // ?

    ASSERT_EQ(correct, res);
}
