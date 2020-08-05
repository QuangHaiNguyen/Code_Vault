#include "pch.h"
extern "C" {
#include "../array_manipulation/array_manipulation.h"
}


namespace my {
namespace project {
namespace {

// The fixture for testing class Foo.
class ArrayTest : public ::testing::Test {
protected:
    // You can remove any or all of the following functions if their bodies would
    // be empty.

    ArrayTest() {
        // You can do set-up work for each test here.
    }

    ~ArrayTest() override {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    void SetUp() override {
        // Code here will be called immediately after the constructor (right
        // before each test).
        
        my_array = (Array*)malloc(sizeof(Array));
        my_array->size = 10;
        my_array->buff_ptr = (int*)malloc(my_array->size * sizeof(int));
        for (int i = 0; i < my_array->size; i++)
        {
            my_array->buff_ptr[i] = i;
        }
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right
        // before the destructor).
        free(my_array->buff_ptr);
        free(my_array);
    }

    // Class members declared here can be used by all tests in the test suite
    // for Foo.
    Array* my_array;
    
};


TEST_F(ArrayTest, test_init_data) {
    int test_buffer[10] = { 0,1,2,3,4,5,6,7,8,9 };
    ASSERT_EQ(my_array->size, 10);
    ASSERT_EQ(memcmp(my_array->buff_ptr, test_buffer,10), 0);
}


TEST_F(ArrayTest, ArrayShiftToLeft_shift_data_in_middle) {
    int cmp_buff[10] = { 0,1,2,4,5,6,7,8,9,9};
    Array_ShiftToLeft(my_array, 3);
    ASSERT_EQ(memcmp(my_array->buff_ptr, cmp_buff, 10), 0);
}

TEST_F(ArrayTest, ArrayShiftToLeft_shift_data_upper_bound) {
    int cmp_buff[10] = { 0,1,2,3,4,5,6,7,8,9 };
    Array_ShiftToLeft(my_array, 9);
    ASSERT_EQ(memcmp(my_array->buff_ptr, cmp_buff, 10), 0);
}

TEST_F(ArrayTest, ArrayShiftToLeft_shift_data_lower_bound) {
    int cmp_buff[10] = { 1,2,3,4,5,6,7,8,9,9 };
    
    Array_ShiftToLeft(my_array, 0);
    ASSERT_EQ(memcmp(my_array->buff_ptr, cmp_buff, 10), 0);
}

TEST_F(ArrayTest, insert_element_middle) {
    int cmp_buff[11] = {0,1,10,2,3,4,5,6,7,8,9};
    
    Array_InsertElement(10,2,my_array);
    ASSERT_EQ(my_array->size, 11);
    ASSERT_EQ(memcmp(my_array->buff_ptr, cmp_buff, 11), 0);
}

TEST_F(ArrayTest, insert_element_bound) {
    int cmp_buff[11] = { 0,1,2,3,4,5,6,7,8,9,10};
    int cmp_buff1[12] = { -1,0,1,2,3,4,5,6,7,8,9,10 };
    
    Array_InsertElement(10, 10, my_array);
    ASSERT_EQ(my_array->size, 11);
    ASSERT_EQ(memcmp(my_array->buff_ptr, cmp_buff, 11), 0);

    Array_InsertElement(-1, 0, my_array);
    ASSERT_EQ(my_array->size, 12);
    ASSERT_EQ(memcmp(my_array->buff_ptr, cmp_buff1, 12), 0);
}

TEST_F(ArrayTest, delete_element_bound) {
    int cmp_buff[9] = { 1,2,3,4,5,6,7,8,9};
    int cmp_buff1[8] = {1,2,3,4,5,6,7,8};
    
    Array_DeleteElement(my_array, 0);
    ASSERT_EQ(my_array->size, 9);
    ASSERT_EQ(memcmp(my_array->buff_ptr, cmp_buff, 9), 0);

    Array_DeleteElement(my_array,8);
    ASSERT_EQ(my_array->size, 8);
    ASSERT_EQ(memcmp(my_array->buff_ptr, cmp_buff1, 8), 0);
}

TEST_F(ArrayTest, delete_element_middle) {
    int cmp_buff[9] = { 0,1,2,3,5,6,7,8,9 };

    Array_DeleteElement(my_array, 4);
    ASSERT_EQ(my_array->size, 9);
    ASSERT_EQ(memcmp(my_array->buff_ptr, cmp_buff, 9), 0);

    my_array->size = 1;
    Array_DeleteElement(my_array, 0);
    ASSERT_EQ(my_array->size, 0);
}


}  // namespace
}  // namespace project
}  // namespace my

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}