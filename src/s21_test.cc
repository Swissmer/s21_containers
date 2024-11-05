#include <gtest/gtest.h>

#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#include "s21_containers.h"
#include "s21_containersplus.h"

/////////////////////////
//        List         //
/////////////////////////

//  ----------- Constructors and operators copy / move -------------

TEST(ListTest, Default_Constructor) {
  s21::List<int> my_list_int;
  std::list<int> std_list_int;

  s21::List<double> my_list_double;
  std::list<double> std_list_double;

  s21::List<std::string> my_list_string;
  std::list<std::string> std_list_string;

  s21::List<char> my_list_char;
  std::list<char> std_list_char;

  EXPECT_EQ(my_list_int.size(), std_list_int.size());
  EXPECT_EQ(std_list_int.size(), 0U);
  EXPECT_EQ(my_list_int.size(), 0U);

  EXPECT_EQ(my_list_double.size(), std_list_double.size());
  EXPECT_EQ(std_list_double.size(), 0U);
  EXPECT_EQ(my_list_double.size(), 0U);

  EXPECT_EQ(my_list_string.size(), std_list_string.size());
  EXPECT_EQ(std_list_string.size(), 0U);
  EXPECT_EQ(my_list_string.size(), 0U);

  EXPECT_EQ(my_list_char.size(), std_list_char.size());
  EXPECT_EQ(std_list_char.size(), 0U);
  EXPECT_EQ(my_list_char.size(), 0U);
}

TEST(ListTest, Param_Zero_Constructor) {
  size_t size = 0U;
  s21::List<int> my_list_int(size);
  std::list<int> std_list_int(size);

  s21::List<double> my_list_double(size);
  std::list<double> std_list_double(size);

  s21::List<std::string> my_list_string(size);
  std::list<std::string> std_list_string(size);

  s21::List<char> my_list_char(size);
  std::list<char> std_list_char(size);

  EXPECT_EQ(my_list_int.size(), std_list_int.size());
  EXPECT_EQ(std_list_int.size(), size);
  EXPECT_EQ(my_list_int.size(), size);

  EXPECT_EQ(my_list_double.size(), std_list_double.size());
  EXPECT_EQ(std_list_double.size(), size);
  EXPECT_EQ(my_list_double.size(), size);

  EXPECT_EQ(my_list_string.size(), std_list_string.size());
  EXPECT_EQ(std_list_string.size(), size);
  EXPECT_EQ(my_list_string.size(), size);

  EXPECT_EQ(my_list_char.size(), std_list_char.size());
  EXPECT_EQ(std_list_char.size(), size);
  EXPECT_EQ(my_list_char.size(), size);
}

TEST(ListTest, Param_Constructor_Small) {
  size_t size = 5U;
  s21::List<int> my_list_int(size);
  std::list<int> std_list_int(size);

  s21::List<double> my_list_double(size);
  std::list<double> std_list_double(size);

  s21::List<std::string> my_list_string(size);
  std::list<std::string> std_list_string(size);

  s21::List<char> my_list_char(size);
  std::list<char> std_list_char(size);

  EXPECT_EQ(my_list_int.size(), std_list_int.size());
  EXPECT_EQ(std_list_int.size(), size);
  EXPECT_EQ(my_list_int.size(), size);
  EXPECT_EQ(my_list_int.max_size(), std_list_int.max_size());

  EXPECT_EQ(my_list_double.size(), std_list_double.size());
  EXPECT_EQ(std_list_double.size(), size);
  EXPECT_EQ(my_list_double.size(), size);
  EXPECT_EQ(my_list_double.max_size(), std_list_double.max_size());

  EXPECT_EQ(my_list_string.size(), std_list_string.size());
  EXPECT_EQ(std_list_string.size(), size);
  EXPECT_EQ(my_list_string.size(), size);
  EXPECT_EQ(my_list_string.max_size(), std_list_string.max_size());

  EXPECT_EQ(my_list_char.size(), std_list_char.size());
  EXPECT_EQ(std_list_char.size(), size);
  EXPECT_EQ(my_list_char.size(), size);
  EXPECT_EQ(my_list_char.max_size(), std_list_char.max_size());
}

TEST(ListTest, Param_Constructor_Big) {
  size_t size = 100U;
  s21::List<int> my_list_int(size);
  std::list<int> std_list_int(size);

  s21::List<double> my_list_double(size);
  std::list<double> std_list_double(size);

  s21::List<std::string> my_list_string(size);
  std::list<std::string> std_list_string(size);

  s21::List<char> my_list_char(size);
  std::list<char> std_list_char(size);

  EXPECT_EQ(my_list_int.size(), std_list_int.size());
  EXPECT_EQ(std_list_int.size(), size);
  EXPECT_EQ(my_list_int.size(), size);
  EXPECT_EQ(my_list_int.max_size(), std_list_int.max_size());

  EXPECT_EQ(my_list_double.size(), std_list_double.size());
  EXPECT_EQ(std_list_double.size(), size);
  EXPECT_EQ(my_list_double.size(), size);
  EXPECT_EQ(my_list_double.max_size(), std_list_double.max_size());

  EXPECT_EQ(my_list_string.size(), std_list_string.size());
  EXPECT_EQ(std_list_string.size(), size);
  EXPECT_EQ(my_list_string.size(), size);
  EXPECT_EQ(my_list_string.max_size(), std_list_string.max_size());

  EXPECT_EQ(my_list_char.size(), std_list_char.size());
  EXPECT_EQ(std_list_char.size(), size);
  EXPECT_EQ(my_list_char.size(), size);
  EXPECT_EQ(my_list_char.max_size(), std_list_char.max_size());
}

TEST(ListTest, Constructor_Initializer) {
  // int
  s21::List<int> my_list_int{1, 2, 3, 4, 5};
  std::list<int> std_list_int{1, 2, 3, 4, 5};

  EXPECT_EQ(my_list_int.size(), std_list_int.size());
  EXPECT_EQ(my_list_int.size(), 5U);
  EXPECT_EQ(my_list_int.front(), std_list_int.front());
  EXPECT_EQ(my_list_int.back(), std_list_int.back());

  // double
  s21::List<double> my_list_double{1.0, 2.0, 3.0, 4.0, 5.0};
  std::list<double> std_list_double{1.0, 2.0, 3.0, 4.0, 5.0};

  EXPECT_EQ(my_list_double.size(), std_list_double.size());
  EXPECT_EQ(my_list_double.size(), 5U);
  EXPECT_EQ(my_list_double.front(), std_list_double.front());
  EXPECT_EQ(my_list_double.back(), std_list_double.back());

  // string
  s21::List<std::string> my_list_string{"My", "name", "is", "Kseniya"};
  std::list<std::string> std_list_string{"My", "name", "is", "Kseniya"};

  EXPECT_EQ(my_list_string.size(), std_list_string.size());
  EXPECT_EQ(my_list_string.size(), 4U);
  EXPECT_EQ(my_list_string.front(), std_list_string.front());
  EXPECT_EQ(my_list_string.back(), std_list_string.back());

  // char
  s21::List<char> my_list_char{'H', 'e', 'l', 'l', 'o'};
  std::list<char> std_list_char{'H', 'e', 'l', 'l', 'o'};

  EXPECT_EQ(my_list_char.size(), std_list_char.size());
  EXPECT_EQ(my_list_char.size(), 5U);
  EXPECT_EQ(my_list_char.front(), std_list_char.front());
  EXPECT_EQ(my_list_char.back(), std_list_char.back());
}

TEST(ListTest, Copy_Constructor) {
  // int
  s21::List<int> list_int{1, 2, 3, 4, 5};
  s21::List<int> list_int_copy(list_int);

  EXPECT_EQ(list_int.size(), list_int_copy.size());
  EXPECT_EQ(list_int.front(), list_int_copy.front());
  EXPECT_EQ(list_int.back(), list_int_copy.back());

  // double
  s21::List<double> list_double{1.0, 2.0, 3.0, 4.0, 5.0};
  s21::List<double> list_double_copy(list_double);

  EXPECT_EQ(list_double.size(), list_double_copy.size());
  EXPECT_EQ(list_double.front(), list_double_copy.front());
  EXPECT_EQ(list_double.back(), list_double_copy.back());

  // string
  s21::List<std::string> list_string{"School", "21"};
  s21::List<std::string> list_string_copy(list_string);

  EXPECT_EQ(list_string.size(), list_string_copy.size());
  EXPECT_EQ(list_string.front(), list_string_copy.front());
  EXPECT_EQ(list_string.back(), list_string_copy.back());

  // char
  s21::List<char> list_char{'l', 'i', 's', 't'};
  s21::List<char> list_char_copy(list_char);

  EXPECT_EQ(list_char.size(), list_char_copy.size());
  EXPECT_EQ(list_char.front(), list_char_copy.front());
  EXPECT_EQ(list_char.back(), list_char_copy.back());
}

TEST(ListTest, MoveConstructor) {
  // int
  s21::List<int> list_int{0, 2, 36, 1, -5};
  s21::List<int> list_int_copy(std::move(list_int));

  EXPECT_EQ(list_int.size(), 0U);
  EXPECT_EQ(list_int_copy.size(), 5U);
  EXPECT_EQ(list_int_copy.front(), 0);
  EXPECT_EQ(list_int_copy.back(), -5);

  // double
  s21::List<double> list_double{-1.0, 22.0, 13.0, -14.0, 50.0};
  s21::List<double> list_double_copy(std::move(list_double));

  EXPECT_EQ(list_double.size(), 0U);
  EXPECT_EQ(list_double_copy.size(), 5U);
  EXPECT_EQ(list_double_copy.front(), -1.0);
  EXPECT_EQ(list_double_copy.back(), 50.0);

  // string
  s21::List<std::string> list_string{"School", "21"};
  s21::List<std::string> list_string_copy(std::move(list_string));

  EXPECT_EQ(list_string.size(), 0U);
  EXPECT_EQ(list_string_copy.size(), 2U);
  EXPECT_EQ(list_string_copy.front(), "School");
  EXPECT_EQ(list_string_copy.back(), "21");

  // char
  s21::List<char> list_char{'l', 'i', 's', 't'};
  s21::List<char> list_char_copy(std::move(list_char));

  EXPECT_EQ(list_char.size(), 0U);
  EXPECT_EQ(list_char_copy.size(), 4U);
  EXPECT_EQ(list_char_copy.front(), 'l');
  EXPECT_EQ(list_char_copy.back(), 't');
}

TEST(ListTest, Copy_Assign) {
  // int
  s21::List<int> list_int(5);
  const s21::List<int> list_int_const(9);
  list_int = list_int_const;

  std::list<int> std_list_int(9);

  EXPECT_EQ(list_int.size(), list_int_const.size());
  EXPECT_EQ(list_int.size(), std_list_int.size());

  // double
  s21::List<double> list_double(9);
  const s21::List<double> list_double_const{1.0, 2.0, 3.0, 4.0, 5.0};
  list_double = list_double_const;

  std::list<double> std_list_double{1.0, 2.0, 3.0, 4.0, 5.0};

  EXPECT_EQ(list_double.size(), list_double_const.size());
  EXPECT_EQ(list_double.size(), std_list_double.size());
  EXPECT_EQ(list_double.front(), std_list_double.front());
  EXPECT_EQ(list_double.back(), std_list_double.back());

  s21::List<double>::iterator it1;
  std::list<double>::iterator it2;

  for (it1 = list_double.begin(), it2 = std_list_double.begin();
       it1 != list_double.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);

  // string
  s21::List<std::string> list_string{"Hello", "world"};
  const s21::List<std::string> list_string_const{"I", "love", "Kazan"};
  list_string = list_string_const;

  EXPECT_EQ(list_string.size(), list_string_const.size());
  EXPECT_EQ(list_string.front(), list_string_const.front());
  EXPECT_EQ(list_string.back(), list_string_const.back());

  s21::List<std::string>::iterator it3;
  s21::List<std::string>::const_iterator it4;

  for (it3 = list_string.begin(), it4 = list_string_const.begin();
       it3 != list_string.end(); ++it3, ++it4)
    EXPECT_EQ(*it3, *it4);

  // char
  s21::List<char> list_char{'V', 'e', 'n', 'e', 'r', 'a'};
  const s21::List<char> list_char_const{'V', 'e', 'n', 'e', 'r', 'a'};
  list_char = list_char_const;

  EXPECT_EQ(list_char.size(), list_char_const.size());
  EXPECT_EQ(list_char.front(), list_char_const.front());
  EXPECT_EQ(list_char.back(), list_char_const.back());

  s21::List<char>::iterator it5;
  s21::List<char>::iterator it6;

  for (it5 = list_char.begin(), it6 = list_char_const.begin();
       it5 != list_char.end(); ++it5, ++it6) {
    EXPECT_EQ(*it5, *it6);
  }

  // copy self
  s21::List<int> my_list(5);
  my_list = my_list;

  std::list<int> std_list(5);
  std_list = std_list;

  EXPECT_EQ(my_list.size(), std_list.size());
}

TEST(ListTest, Move_Assign) {
  // int
  s21::List<int> list_int{1, 2, 3, 4, 5};
  s21::List<int> list_int_move(9);
  list_int = std::move(list_int_move);

  std::list<int> std_list_int{1, 2, 3, 4, 5};
  std::list<int> std_list_int_move(9);
  std_list_int = std::move(std_list_int_move);

  EXPECT_EQ(list_int.size(), std_list_int.size());
  EXPECT_EQ(list_int_move.size(), std_list_int_move.size());
  EXPECT_EQ(list_int_move.size(), 0U);

  // double
  s21::List<double> list_double{2.0};
  s21::List<double> list_double_move{1.0, 9.0, -0.5};
  list_double = std::move(list_double_move);

  std::list<double> std_list_double{8.0};
  std::list<double> std_list_double_move{1.0, 9.0, -0.5};
  std_list_double = std::move(std_list_double_move);

  EXPECT_EQ(list_double.size(), std_list_double.size());
  EXPECT_EQ(list_double_move.size(), std_list_double_move.size());
  EXPECT_EQ(list_double_move.size(), 0U);

  s21::List<double>::iterator it1;
  std::list<double>::iterator it2;

  for (it1 = list_double.begin(), it2 = std_list_double.begin();
       it1 != list_double.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);

  // string
  s21::List<std::string> list_string(10);
  s21::List<std::string> list_string_move(1);
  list_string = std::move(list_string_move);

  std::list<std::string> std_list_string(10);
  std::list<std::string> std_list_string_move(1);
  std_list_string = std::move(std_list_string_move);

  EXPECT_EQ(list_string.size(), std_list_string.size());
  EXPECT_EQ(list_string.size(), 1U);
  EXPECT_EQ(list_string_move.size(), std_list_string_move.size());
  EXPECT_EQ(list_string_move.size(), 0U);

  // char
  s21::List<char> list_char;
  s21::List<char> list_char_move;
  list_char = std::move(list_char_move);

  std::list<char> std_list_char;
  std::list<char> std_list_char_move;
  std_list_char = std::move(std_list_char_move);

  EXPECT_EQ(list_char.size(), std_list_char.size());
  EXPECT_EQ(list_char.size(), 0U);
  EXPECT_EQ(list_char_move.size(), std_list_char_move.size());
  EXPECT_EQ(list_char_move.size(), 0U);

  // int UB if self move - тест проходит на убунту, на маке выдает ошибку при
  // попытке переместить std::list сам в себя s21::List<int> my_list(5); my_list
  // = std::move(my_list);

  // std::list<int> std_list(5);
  // std_list = std::move(std_list);

  // EXPECT_EQ(my_list.size(), std_list.size());
}

// ----------- Iterators -------------
TEST(ListTest, Iterator_Begin_and_End) {
  // int
  // for list<int> and list<double> in std lib iterator end() is UB
  // in std::list<int> it contains total number of elements in container
  // thats why we cant compare iterators end of std lib and our
  s21::List<int> list_int{1, 2, 3, 4, 5, 6};
  std::list<int> std_int{1, 2, 3, 4, 5, 6};
  s21::List<int> list_int2;
  std::list<int> std_int2;
  s21::List<int>::iterator it1;
  std::list<int>::iterator it2;

  // для пустых листов std::list<int> итераторы end() равны
  EXPECT_EQ(*list_int2.begin(), *std_int2.begin());
  EXPECT_EQ(*list_int2.end(), *std_int2.end());

  // для непустых = size
  EXPECT_EQ(*list_int.begin(), *std_int.begin());
  EXPECT_EQ(list_int.size(), *std_int.end());

  // double
  s21::List<double> list_double{0.0, 2.0, 103.0, 4.7, 50.9};
  std::list<double> std_double{0.0, 2.0, 103.0, 4.7, 50.9};
  s21::List<double>::iterator it3;
  std::list<double>::iterator it4;

  EXPECT_EQ(*list_double.begin(), *std_double.begin());
  // std::cout << *std_double.end() << std::endl;
  // std::cout << *list_double.end() << std::endl;
  // здесь тесты проходят, потому что в std_double.end() будет значение близкое
  // к 0, НО на убунте будет ошибка
  for (it3 = list_double.begin(), it4 = std_double.begin();
       it3 != list_double.end(); ++it3, ++it4)
    EXPECT_EQ(*it3, *it4);

  // string
  s21::List<std::string> list_string{"0.0, 2.0, 103.0, 4.7, 50.9", "container",
                                     "lo"};
  std::list<std::string> std_string{"0.0, 2.0, 103.0, 4.7, 50.9", "container",
                                    "lo"};

  s21::List<std::string>::iterator it5;
  std::list<std::string>::iterator it6;

  EXPECT_EQ(*list_string.begin(), *std_string.begin());
  // для не пустых листов итераторы std::list<std::string> равны последнему
  // элементу списка, не фейковой ноде, поэтому их можно сравнивать на маке
  // НО на убунте будет fail
  EXPECT_EQ(*list_string.end(), *std_string.end());

  for (it5 = list_string.begin(), it6 = std_string.begin();
       it5 != list_string.end(); ++it5, ++it6)
    EXPECT_EQ(*it5, *it6);

  // char
  // UB при попытке вызвать итератор end()
  s21::List<char> list_char{'c', 'h', 'a', 'r'};
  std::list<char> std_char{'c', 'h', 'a', 'r'};
  // если закомментировать строку ниже, то тест на сравнение begin() не проходит
  // - ?, на убунте проходит и без std::cout
  std::cout << *std_char.begin() << std::endl;
  EXPECT_EQ(*list_char.begin(), *std_char.begin());
}

TEST(ListTest, Iterator_Insert) {
  // int
  // 1 - пустые листы
  s21::List<int> list_int;
  std::list<int> std_int;

  s21::List<int>::iterator it1 = list_int.begin();
  list_int.insert(it1, 1);
  list_int.insert(it1, 2);
  ++it1;
  list_int.insert(it1, 5);

  std::list<int>::iterator it2 = std_int.begin();
  std_int.insert(it2, 1);
  std_int.insert(it2, 2);
  ++it2;
  std_int.insert(it2, 5);

  EXPECT_EQ(list_int.size(), std_int.size());
  EXPECT_EQ(*list_int.begin(), *std_int.begin());
  EXPECT_EQ(list_int.size(), *std_int.end());
  EXPECT_EQ(list_int.back(), std_int.back());

  for (it1 = list_int.begin(), it2 = std_int.begin(); it1 != list_int.end();
       ++it1, ++it2) {
    EXPECT_EQ(*it1, *it2);
  }

  // 2 - заполненные листы
  s21::List<int> list_int2{1, 2, 3, 5, 8, 10};
  std::list<int> std_int2{1, 2, 3, 5, 8, 10};

  s21::List<int>::iterator it3 = list_int2.begin();
  list_int2.insert(it3, 200);
  list_int2.insert(it3, 2600);
  ++it3;
  // list_int2.insert(it3, 1000);

  std::list<int>::iterator it4 = std_int2.begin();
  std_int2.insert(it4, 200);
  std_int2.insert(it4, 2600);
  ++it4;
  // std_int2.insert(it4, 1000);

  for (it3 = list_int2.begin(), it4 = std_int2.begin(); it3 != list_int2.end();
       ++it3, ++it4) {
    EXPECT_EQ(*it3, *it4);
  }

  EXPECT_EQ(list_int2.size(), std_int2.size());
  EXPECT_EQ(*list_int2.begin(), *std_int2.begin());
  EXPECT_EQ(list_int2.size(), *std_int2.end());
  EXPECT_EQ(list_int2.back(), std_int2.back());

  // double
  // 1 - пустой лист
  s21::List<double> list_double;
  std::list<double> std_double;

  s21::List<double>::iterator it5 = list_double.begin();
  list_double.insert(it5, 3.0);
  list_double.insert(it5, 3.0);
  list_double.insert(it5, 3.0);
  --it5;
  list_double.insert(it5, 5.0);

  std::list<double>::iterator it6 = std_double.begin();
  std_double.insert(it6, 3.0);
  std_double.insert(it6, 3.0);
  std_double.insert(it6, 3.0);
  --it6;
  std_double.insert(it6, 5.0);

  for (it5 = list_double.begin(), it6 = std_double.begin();
       it5 != list_double.end(); ++it5, ++it6) {
    EXPECT_EQ(*it5, *it6);
    // std::cout << *it5 << "  -  " << *it6 << std::endl;
  }

  // 2 - заполненный лист
  s21::List<double> list_double2{2.0, 44.9, -0.2, -0.111, 32.9, 87.05};
  std::list<double> std_double2{2.0, 44.9, -0.2, -0.111, 32.9, 87.05};

  s21::List<double>::iterator it7 = list_double2.begin();
  ++it7;
  ++it7;
  ++it7;
  list_double2.insert(it7, 3.0);
  list_double2.insert(it7, 3.0);
  list_double2.insert(it7, 3.0);

  std::list<double>::iterator it8 = std_double2.begin();
  ++it8;
  ++it8;
  ++it8;
  std_double2.insert(it8, 3.0);
  std_double2.insert(it8, 3.0);
  std_double2.insert(it8, 3.0);

  for (it7 = list_double2.begin(), it8 = std_double2.begin();
       it7 != list_double2.end(); ++it7, ++it8) {
    EXPECT_EQ(*it7, *it8);
  }

  // string
  // 1 - пустой лист
  s21::List<std::string> list_string;
  std::list<std::string> std_string;

  s21::List<std::string>::iterator it9 = list_string.end();
  list_string.insert(it9, "world");
  --it9;
  list_string.insert(it9, "hello");
  std::list<std::string>::iterator it10 = std_string.end();
  std_string.insert(it10, "world");
  --it10;
  std_string.insert(it10, "hello");

  for (it9 = list_string.begin(), it10 = std_string.begin();
       it9 != list_string.end(); ++it9, ++it10) {
    EXPECT_EQ(*it9, *it10);
  }

  // 2 - заполненный лист
  s21::List<std::string> list_string2{"The", "is"};
  std::list<std::string> std_string2{"The", "is"};

  s21::List<std::string>::iterator it11 = list_string2.end();
  list_string2.insert(it11, "comming");
  --it11;
  --it11;
  list_string2.insert(it11, "winter");

  std::list<std::string>::iterator it12 = std_string2.end();
  std_string2.insert(it12, "comming");
  --it12;
  --it12;
  std_string2.insert(it12, "winter");

  for (it11 = list_string2.begin(), it12 = std_string2.begin();
       it11 != list_string2.end(); ++it11, ++it12) {
    EXPECT_EQ(*it11, *it12);
  }

  // char
  // 1 -  пустой лист
  s21::List<char> list_char;
  std::list<char> std_char;

  s21::List<char>::iterator it13 = list_char.begin();
  list_char.insert(it13, 'e');
  list_char.insert(it13, 'x');
  list_char.insert(it13, 'i');
  list_char.insert(it13, 't');

  std::list<char>::iterator it14 = std_char.begin();
  std_char.insert(it14, 'e');
  std_char.insert(it14, 'x');
  std_char.insert(it14, 'i');
  std_char.insert(it14, 't');

  for (it13 = list_char.begin(), it14 = std_char.begin();
       it13 != list_char.end(); ++it13, ++it14) {
    EXPECT_EQ(*it13, *it14);
  }

  // 2 - заполненный лист
  s21::List<char> list_char2{'l', 't'};
  std::list<char> std_char2{'l', 't'};

  s21::List<char>::iterator it15 = list_char2.end();
  --it15;
  list_char2.insert(it15, 's');
  --it15;
  list_char2.insert(it15, 'i');

  std::list<char>::iterator it16 = std_char2.end();
  --it16;
  std_char2.insert(it16, 's');
  --it16;
  std_char2.insert(it16, 'i');

  for (it15 = list_char2.begin(), it16 = std_char2.begin();
       it15 != list_char2.end(); ++it15, ++it16) {
    EXPECT_EQ(*it15, *it16);
  }
}

TEST(ListTest, Reverse) {
  // int
  // 1 - заполненный лист
  s21::List<int> list_int{1, 2, 4, 7, 1, 0};
  std::list<int> std_int{1, 2, 4, 7, 1, 0};
  list_int.reverse();
  std_int.reverse();

  EXPECT_EQ(list_int.front(), std_int.front());
  EXPECT_EQ(list_int.back(), std_int.back());
  EXPECT_EQ(list_int.size(), std_int.size());

  // 2 - пустой лист
  s21::List<int> list_int2;
  std::list<int> std_int2;
  list_int2.reverse();
  std_int2.reverse();

  EXPECT_EQ(list_int2.front(), std_int2.front());
  EXPECT_EQ(list_int2.back(), std_int2.back());
  // std::cout << std_int2.back() << std::endl;
  EXPECT_EQ(list_int2.size(), std_int2.size());

  // 3 - лист из 1 элемента
  s21::List<int> list_int3(1);
  std::list<int> std_int3(1);
  list_int3.reverse();
  std_int3.reverse();

  EXPECT_EQ(list_int3.front(), std_int3.front());
  EXPECT_EQ(list_int3.back(), std_int3.back());
  EXPECT_EQ(list_int3.size(), std_int3.size());

  // double
  // 1 - заполненный лист
  s21::List<double> list_double{0.0, 2.0, 8.1, -0.9, -19.7};
  std::list<double> std_double{0.0, 2.0, 8.1, -0.9, -19.7};
  list_double.reverse();
  std_double.reverse();

  EXPECT_EQ(list_double.front(), std_double.front());
  EXPECT_EQ(list_double.back(), std_double.back());
  EXPECT_EQ(list_double.size(), std_double.size());

  // 2 - пустой лист
  s21::List<double> list_double2;
  std::list<double> std_double2;
  list_double2.reverse();
  std_double2.reverse();

  EXPECT_EQ(list_double2.front(), std_double2.front());
  EXPECT_EQ(list_double2.back(), std_double2.back());
  // std::cout << std_double2.back() << std::endl;
  EXPECT_EQ(list_double2.size(), std_double2.size());

  // 3 - лист из 1 элемента
  s21::List<double> list_double3{3.0};
  std::list<double> std_double3{3.0};
  list_double3.reverse();
  std_double3.reverse();

  EXPECT_EQ(list_double3.front(), std_double3.front());
  EXPECT_EQ(list_double3.back(), std_double3.back());
  EXPECT_EQ(list_double3.size(), std_double3.size());

  // string
  // 1 - заполненный лист
  s21::List<std::string> list_string{"Kazan", "love", "I"};
  std::list<std::string> std_string{"Kazan", "love", "I"};
  list_string.reverse();
  std_string.reverse();

  EXPECT_EQ(list_string.front(), std_string.front());
  EXPECT_EQ(list_string.back(), std_string.back());
  EXPECT_EQ(list_string.size(), std_string.size());
  s21::List<std::string>::iterator it1;
  std::list<std::string>::iterator it2;

  for (it1 = list_string.begin(), it2 = std_string.begin();
       it1 != list_string.end(); ++it1, ++it2) {
    EXPECT_EQ(*it1, *it2);
    //  std::cout << *it1 << "  -  " << *it2 << std::endl;
  }

  // 2 - пустой лист
  s21::List<std::string> list_string2;
  std::list<std::string> std_string2;
  list_string2.reverse();
  std_string2.reverse();

  // закоммичеснные тесты - UB оригинального контейнера
  // EXPECT_EQ(list_string2.front(), std_string2.front());
  // EXPECT_EQ(list_string2.back(), std_string2.back());
  EXPECT_EQ(list_string2.size(), std_string2.size());

  // 3 - лист из 1 элемента
  s21::List<std::string> list_string3{"school21"};
  std::list<std::string> std_string3{"school21"};
  list_string3.reverse();
  std_string3.reverse();

  EXPECT_EQ(list_string3.front(), std_string3.front());
  EXPECT_EQ(list_string3.back(), std_string3.back());
  EXPECT_EQ(list_string3.size(), std_string3.size());

  // char
  // 1 - заполненный лист
  s21::List<char> list_char{'1', '2', 's'};
  std::list<char> std_char{'1', '2', 's'};
  list_char.reverse();
  std_char.reverse();

  EXPECT_EQ(list_char.front(), std_char.front());
  EXPECT_EQ(list_char.back(), std_char.back());
  EXPECT_EQ(list_char.size(), std_char.size());
  s21::List<char>::iterator it3;
  std::list<char>::iterator it4;

  for (it3 = list_char.begin(), it4 = std_char.begin(); it3 != list_char.end();
       ++it3, ++it4) {
    EXPECT_EQ(*it3, *it4);
    //  std::cout << *it3 << "  -  " << *it4 << std::endl;
  }

  // 2 - пустой лист
  s21::List<char> list_char2;
  std::list<char> std_char2;
  list_char2.reverse();
  std_char2.reverse();

  // закоммичеснные тесты - UB оригинального контейнера
  // EXPECT_EQ(list_char2.front(), std_char2.front());
  // EXPECT_EQ(list_char2.back(), std_char2.back());
  EXPECT_EQ(list_char2.size(), std_char2.size());

  // 3 - лист из 1 элемента
  s21::List<char> list_char3{'x'};
  std::list<char> std_char3{'x'};
  list_string3.reverse();
  std_string3.reverse();

  EXPECT_EQ(list_char3.front(), std_char3.front());
  EXPECT_EQ(list_char3.back(), std_char3.back());
  EXPECT_EQ(list_char3.size(), std_char3.size());
}

TEST(ListTest, Merge) {
  // int
  s21::List<int> list_int{6, 5, 4, 3, 2, 1, 0};
  s21::List<int> list_int2{-1, -2, -3, -7, -8, -9, 0};
  s21::List<int> list_int3{9, 0, 7};
  s21::List<int> list_int4{-1, 9, 0, -87};
  s21::List<int> list_int5(6);

  std::list<int> std_int{6, 5, 4, 3, 2, 1, 0};
  std::list<int> std_int2{-1, -2, -3, -7, -8, -9, 0};
  std::list<int> std_int3{9, 0, 7};
  std::list<int> std_int4{-1, 9, 0, -87};
  std::list<int> std_int5(6);

  // с самим собой
  list_int.merge(list_int);
  std_int.merge(std_int);

  s21::List<int>::iterator it1;
  std::list<int>::iterator it2;

  for (it1 = list_int.begin(), it2 = std_int.begin(); it1 != list_int.end();
       ++it1, ++it2) {
    EXPECT_EQ(*it1, *it2);
  }

  EXPECT_EQ(list_int.front(), std_int.front());
  EXPECT_EQ(list_int.back(), std_int.back());
  EXPECT_EQ(list_int.size(), std_int.size());

  // с другим листом такого же размера

  list_int.merge(list_int2);
  std_int.merge(std_int2);

  s21::List<int>::iterator it3;
  std::list<int>::iterator it4;

  EXPECT_EQ(list_int2.size(), std_int2.size());
  EXPECT_EQ(list_int2.size(), 0U);
  EXPECT_EQ(std_int2.size(), 0U);

  for (it3 = list_int.begin(), it4 = std_int.begin(); it3 != list_int.end();
       ++it3, ++it4) {
    EXPECT_EQ(*it3, *it4);
    // std::cout << *it3 << "  -  " << *it4 << std::endl;
  }

  EXPECT_EQ(list_int.front(), std_int.front());
  EXPECT_EQ(list_int.back(), std_int.back());
  EXPECT_EQ(list_int.size(), std_int.size());

  // c листом меньшего размера

  list_int.merge(list_int3);
  std_int.merge(std_int3);

  s21::List<int>::iterator it5;
  std::list<int>::iterator it6;

  EXPECT_EQ(list_int3.size(), std_int3.size());
  EXPECT_EQ(list_int3.size(), 0U);
  EXPECT_EQ(std_int3.size(), 0U);

  for (it5 = list_int.begin(), it6 = std_int.begin(); it5 != list_int.end();
       ++it5, ++it6) {
    EXPECT_EQ(*it5, *it6);
    // std::cout << *it5 << "  -  " << *it6 << std::endl;
  }

  // с листом большего размера

  list_int4.merge(list_int5);
  std_int4.merge(std_int5);

  s21::List<int>::iterator it7;
  std::list<int>::iterator it8;

  EXPECT_EQ(list_int5.size(), std_int5.size());
  EXPECT_EQ(list_int5.size(), 0U);
  EXPECT_EQ(std_int5.size(), 0U);

  for (it7 = list_int4.begin(), it8 = std_int4.begin(); it7 != list_int4.end();
       ++it7, ++it8) {
    EXPECT_EQ(*it7, *it8);
    // std::cout << *it7 << "  -  " << *it8 << std::endl;
  }

  // string
  s21::List<std::string> list_string{"Hello", "world", "metaverse"};
  s21::List<std::string> list_string2{"List", "Merge", "test"};
  s21::List<std::string> list_string3{"gods", "and", "monsters"};
  s21::List<std::string> list_string4{"Aboba"};
  s21::List<std::string> list_string5(10);

  std::list<std::string> std_string{"Hello", "world", "metaverse"};
  std::list<std::string> std_string2{"List", "Merge", "test"};
  std::list<std::string> std_string3{"gods", "and", "monsters"};
  std::list<std::string> std_string4{"Aboba"};
  std::list<std::string> std_string5(10);

  // c самим собой
  list_string.merge(list_string);
  std_string.merge(std_string);

  s21::List<std::string>::iterator it9;
  std::list<std::string>::iterator it10;

  for (it9 = list_string.begin(), it10 = std_string.begin();
       it9 != list_string.end(); ++it9, ++it10) {
    EXPECT_EQ(*it9, *it10);
    // std::cout << *it9 << "  -  " << *it10 << std::endl;
  }

  EXPECT_EQ(list_string.front(), std_string.front());
  EXPECT_EQ(list_string.back(), std_string.back());
  EXPECT_EQ(list_string.size(), std_string.size());

  // с листом такого же размера
  list_string.merge(list_string2);
  std_string.merge(std_string2);

  s21::List<std::string>::iterator it11;
  std::list<std::string>::iterator it12;

  EXPECT_EQ(list_string2.size(), std_string2.size());
  EXPECT_EQ(list_string2.size(), 0U);
  EXPECT_EQ(std_string2.size(), 0U);

  for (it11 = list_string.begin(), it12 = std_string.begin();
       it11 != list_string.end(); ++it11, ++it12) {
    EXPECT_EQ(*it11, *it12);
    // std::cout << *it11 << "  -  " << *it12 << std::endl;
  }

  EXPECT_EQ(list_string.front(), std_string.front());
  EXPECT_EQ(list_string.back(), std_string.back());
  EXPECT_EQ(list_string.size(), std_string.size());

  // с листом меньшего размера
  list_string.merge(list_string3);
  std_string.merge(std_string3);

  s21::List<std::string>::iterator it13;
  std::list<std::string>::iterator it14;

  EXPECT_EQ(list_string3.size(), std_string3.size());
  EXPECT_EQ(list_string3.size(), 0U);
  EXPECT_EQ(std_string3.size(), 0U);

  for (it13 = list_string.begin(), it14 = std_string.begin();
       it13 != list_string.end(); ++it13, ++it14) {
    EXPECT_EQ(*it13, *it14);
    // std::cout << *it13 << "  -  " << *it14 << std::endl;
  }

  EXPECT_EQ(list_string.front(), std_string.front());
  EXPECT_EQ(list_string.back(), std_string.back());
  EXPECT_EQ(list_string.size(), std_string.size());

  // с листом большего размера
  list_string4.merge(list_string5);
  std_string4.merge(std_string5);

  s21::List<std::string>::iterator it15;
  std::list<std::string>::iterator it16;

  EXPECT_EQ(list_string5.size(), std_string5.size());
  EXPECT_EQ(list_string5.size(), 0U);
  EXPECT_EQ(std_string5.size(), 0U);

  for (it15 = list_string4.begin(), it16 = std_string4.begin();
       it15 != list_string4.end(); ++it15, ++it16) {
    EXPECT_EQ(*it15, *it16);
    // std::cout << *it15 << "  -  " << *it16 << std::endl;
  }

  EXPECT_EQ(list_string4.front(), std_string4.front());
  EXPECT_EQ(list_string4.back(), std_string4.back());
  EXPECT_EQ(list_string4.size(), std_string4.size());
}

TEST(ListTest, Sort) {
  // int
  s21::List<int> list_int{5, 4, 3, 2, 1, 0, 1};
  std::list<int> std_int{5, 4, 3, 2, 1, 0, 1};
  s21::List<int> list_int2{555};
  std::list<int> std_int2{555};
  s21::List<int> list_int3;
  std::list<int> std_int3;

  // заполненный лист
  list_int.sort();
  std_int.sort();

  EXPECT_EQ(list_int.front(), std_int.front());
  EXPECT_EQ(list_int.back(), std_int.back());
  EXPECT_EQ(list_int.size(), std_int.size());

  // лист из 1 элемента
  list_int2.sort();
  std_int2.sort();

  EXPECT_EQ(list_int2.front(), std_int2.front());
  EXPECT_EQ(list_int2.back(), std_int2.back());
  EXPECT_EQ(list_int2.size(), std_int2.size());

  // пустой лист
  list_int3.sort();
  std_int3.sort();

  EXPECT_EQ(list_int3.front(), std_int3.front());
  EXPECT_EQ(list_int3.back(), std_int3.back());
  EXPECT_EQ(list_int3.size(), std_int3.size());

  s21::List<int>::iterator it1;
  std::list<int>::iterator it2;
  for (it1 = list_int.begin(), it2 = std_int.begin(); it1 != list_int.end();
       ++it1, ++it2) {
    EXPECT_EQ(*it1, *it2);
    // std::cout << *it1 << "  -  " << *it2 << std::endl;
  }

  s21::List<int>::iterator it3;
  std::list<int>::iterator it4;
  for (it3 = list_int2.begin(), it4 = std_int2.begin(); it3 != list_int2.end();
       ++it3, ++it4) {
    EXPECT_EQ(*it3, *it4);
    // std::cout << *it3 << "  -  " << *it4 << std::endl;
  }

  s21::List<int>::iterator it7;
  std::list<int>::iterator it8;
  for (it7 = list_int3.begin(), it8 = std_int3.begin(); it7 != list_int3.end();
       ++it7, ++it8) {
    EXPECT_EQ(*it7, *it8);
    // std::cout << *it7 << "  -  " << *it8 << std::endl;
  }

  // string
  s21::List<std::string> list_string{"Hello", "world", "metaverse",
                                     "Aboba", "aboba", "sotring"};
  s21::List<std::string> list_string2{"List"};
  s21::List<std::string> list_string3;

  std::list<std::string> std_string{"Hello", "world", "metaverse",
                                    "Aboba", "aboba", "sotring"};
  std::list<std::string> std_string2{"List"};
  std::list<std::string> std_string3;

  // заполненный список
  list_string.sort();
  std_string.sort();

  EXPECT_EQ(list_string.front(), std_string.front());
  EXPECT_EQ(list_string.back(), std_string.back());
  EXPECT_EQ(list_string.size(), std_string.size());

  // список из 1 элемента
  list_string2.sort();
  std_string2.sort();

  EXPECT_EQ(list_string2.front(), std_string2.front());
  EXPECT_EQ(list_string2.back(), std_string2.back());
  EXPECT_EQ(list_string2.size(), std_string2.size());

  // пустой список
  list_string3.sort();
  std_string3.sort();

  EXPECT_EQ(list_string3.front(), std_string3.front());
  EXPECT_EQ(list_string3.back(), std_string3.back());
  EXPECT_EQ(list_string3.size(), std_string3.size());

  s21::List<std::string>::iterator it9;
  std::list<std::string>::iterator it10;
  for (it9 = list_string.begin(), it10 = std_string.begin();
       it9 != list_string.end(); ++it9, ++it10) {
    EXPECT_EQ(*it9, *it10);
    // std::cout << *it9 << "  -  " << *it10 << std::endl;
  }

  s21::List<std::string>::iterator it11;
  std::list<std::string>::iterator it12;
  for (it11 = list_string2.begin(), it12 = std_string2.begin();
       it11 != list_string2.end(); ++it11, ++it12) {
    EXPECT_EQ(*it11, *it12);
    // std::cout << *it11 << "  -  " << *it12 << std::endl;
  }

  s21::List<std::string>::iterator it13;
  std::list<std::string>::iterator it14;
  for (it13 = list_string3.begin(), it14 = std_string3.begin();
       it13 != list_string3.end(); ++it13, ++it14) {
    EXPECT_EQ(*it13, *it14);
  }
}

TEST(ListTest, Uniqe) {
  // int
  s21::List<int> list_int;
  s21::List<int> list_int2{0, 1, 2, 3, 4, 5, 6, 7};
  s21::List<int> list_int3{9, 9, 9, 0, 0, 9, 9, 0, 1, 2, 3, 4};

  list_int.unique();
  list_int2.unique();
  list_int3.unique();

  std::list<int> std_int;
  std::list<int> std_int2{0, 1, 2, 3, 4, 5, 6, 7};
  std::list<int> std_int3{9, 9, 9, 0, 0, 9, 9, 0, 1, 2, 3, 4};

  std_int.unique();
  std_int2.unique();
  std_int3.unique();

  s21::List<int>::iterator it1;
  std::list<int>::iterator it2;

  for (it1 = list_int.begin(), it2 = std_int.begin(); it1 != list_int.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);

  EXPECT_EQ(list_int.size(), std_int.size());
  EXPECT_EQ(list_int.front(), std_int.front());
  EXPECT_EQ(list_int.back(), std_int.back());

  s21::List<int>::iterator it3;
  std::list<int>::iterator it4;

  for (it3 = list_int2.begin(), it4 = std_int2.begin(); it3 != list_int2.end();
       ++it3, ++it4) {
    EXPECT_EQ(*it3, *it4);
    // std::cout << *it3 << "  -  " << *it4 << std::endl;
  }

  EXPECT_EQ(list_int2.size(), std_int2.size());
  EXPECT_EQ(list_int2.front(), std_int2.front());
  EXPECT_EQ(list_int2.back(), std_int2.back());

  s21::List<int>::iterator it5;
  std::list<int>::iterator it6;

  for (it5 = list_int3.begin(), it6 = std_int3.begin(); it5 != list_int3.end();
       ++it5, ++it6) {
    EXPECT_EQ(*it5, *it6);
    // std::cout << *it5 << "  -  " << *it6 << std::endl;
  }

  EXPECT_EQ(list_int3.size(), std_int3.size());
  EXPECT_EQ(list_int3.front(), std_int3.front());
  EXPECT_EQ(list_int3.back(), std_int3.back());
}

TEST(ListTest, Splice) {
  // int
  s21::List<int> list_int{1, 9, 0, 2, 34, 92};
  s21::List<int> list_int2{21, 2, 8, 2};

  std::list<int> std_int{1, 9, 0, 2, 34, 92};
  std::list<int> std_int2{21, 2, 8, 2};

  s21::List<int>::iterator it1 = list_int.begin();
  it1++;
  it1++;
  std::list<int>::iterator it2 = std_int.begin();
  it2++;
  it2++;

  list_int.splice(it1, list_int2);
  std_int.splice(it2, std_int2);

  // std::cout << *it1 << "  -  " << *it2 << std::endl;

  EXPECT_EQ(list_int.size(), std_int.size());
  EXPECT_EQ(list_int.front(), std_int.front());
  EXPECT_EQ(list_int.back(), std_int.back());

  EXPECT_EQ(list_int2.size(), std_int2.size());
  EXPECT_EQ(list_int2.size(), 0U);
  EXPECT_EQ(list_int2.size(), 0U);

  s21::List<int>::iterator my_itr;
  std::list<int>::iterator std_itr;

  for (my_itr = list_int.begin(), std_itr = std_int.begin();
       my_itr != list_int.end(); ++my_itr, ++std_itr) {
    EXPECT_EQ(*my_itr, *std_itr);
    // std::cout << *my_itr << "  -  " << *std_itr << std::endl;
  }

  my_itr = list_int2.begin();
  std_itr = std_int2.begin();

  list_int2.splice(my_itr, list_int);
  std_int2.splice(std_itr, std_int);

  for (my_itr = list_int2.begin(), std_itr = std_int2.begin();
       my_itr != list_int2.end(); ++my_itr, ++std_itr) {
    EXPECT_EQ(*my_itr, *std_itr);
    // std::cout << *my_itr << "  -  " << *std_itr << std::endl;
  }

  EXPECT_EQ(list_int2.size(), std_int2.size());
  EXPECT_EQ(list_int2.front(), std_int2.front());
  EXPECT_EQ(list_int2.back(), std_int2.back());

  EXPECT_EQ(list_int.size(), std_int.size());
  EXPECT_EQ(list_int.size(), 0U);
  EXPECT_EQ(list_int.size(), 0U);
}

TEST(ListTest, Insert_Many) {
  // int
  s21::List<int> list_int;
  s21::List<int> list_int2{0, 0, 0, 0};
  s21::List<int> check_int{3, 2, 1, 0, 0, 0, 0};
  s21::List<int> check_int2{3, 2, 1};

  s21::List<int>::iterator it1 = list_int.begin();
  s21::List<int>::iterator it2 = list_int2.begin();

  list_int.insert_many(it1, 1, 2, 3);
  list_int2.insert_many(it2, 1, 2, 3);

  for (s21::List<int>::iterator i = list_int.begin(), j = check_int2.begin();
       j != check_int2.end(); ++i, ++j)
    EXPECT_EQ(*i, *j);

  for (s21::List<int>::iterator i = list_int2.begin(), j = check_int.begin();
       j != check_int.end(); ++i, ++j)
    EXPECT_EQ(*i, *j);

  // std::cout << "list_int:" << std::endl;
  // for (s21::List<int>::iterator i = list_int.begin(); i != list_int.end();
  // ++i) std::cout << *i << std::endl;

  // std::cout << std::endl;
  // std::cout << "list_int2:" << std::endl;
  // for (s21::List<int>::iterator i = list_int2.begin(); i != list_int2.end();
  // ++i) std::cout << *i << std::endl;

  // double
  s21::List<double> list_double;
  s21::List<double> list_double2{1.0, 9.0, 0.0};
  s21::List<double> check_double{0.2, 0.1, 0.0};
  s21::List<double> check_double2{1.0, 9.0, 0.2, 0.1, 0.0, 0.0};

  s21::List<double>::iterator it3 = list_double.begin();
  s21::List<double>::iterator it4 = list_double2.begin();
  ++it4;
  ++it4;

  list_double.insert_many(it3, 0.0, 0.1, 0.2);
  list_double2.insert_many(it4, 0.0, 0.1, 0.2);

  for (s21::List<double>::iterator i = list_double.begin(),
                                   j = check_double.begin();
       i != list_double.end(); ++i, ++j)
    EXPECT_EQ(*i, *j);

  for (s21::List<double>::iterator i = list_double2.begin(),
                                   j = check_double2.begin();
       i != list_double2.end(); ++i, ++j)
    EXPECT_EQ(*i, *j);

  // std::cout << std::endl;
  // std::cout << "list_double:" << std::endl;
  // for (s21::List<double>::iterator i = list_double.begin(); i !=
  // list_double.end(); ++i) std::cout << *i << std::endl;

  // std::cout << std::endl;
  // std::cout << "list_double2:" << std::endl;
  // for (s21::List<double>::iterator i = list_double2.begin(); i !=
  // list_double2.end(); ++i) std::cout << *i << std::endl;

  // string
  s21::List<std::string> list_string;
  s21::List<std::string> list_string2{"Hello"};
  s21::List<std::string> check_string{"world", "!"};
  s21::List<std::string> check_string2{"Hello", "world", "!"};

  s21::List<std::string>::iterator it5 = list_string.begin();
  s21::List<std::string>::iterator it6 = list_string2.end();

  list_string.insert_many(it5, "!", "world");
  list_string2.insert_many(it6, "!", "world");

  for (s21::List<std::string>::iterator i = list_string.begin(),
                                        j = check_string.begin();
       i != list_string.end(); ++i, ++j)
    EXPECT_EQ(*i, *j);

  for (s21::List<std::string>::iterator i = list_string2.begin(),
                                        j = check_string2.begin();
       i != list_string2.end(); ++i, ++j)
    EXPECT_EQ(*i, *j);

  // std::cout << std::endl;
  // std::cout << "list_string:" << std::endl;
  // for (s21::List<std::string>::iterator i = list_string.begin(); i !=
  // list_string.end(); ++i) std::cout << *i << std::endl;

  // std::cout << std::endl;
  // std::cout << "list_string2:" << std::endl;
  // for (s21::List<std::string>::iterator i = list_string2.begin(); i !=
  // list_string2.end(); ++i) std::cout << *i << std::endl;

  // char
  s21::List<char> list_char;
  s21::List<char> list_char2{'h', 'a', 'r'};
  s21::List<char> check{'c', 'h', 'a', 'r'};

  s21::List<char>::iterator it7 = list_char.begin();
  s21::List<char>::iterator it8 = list_char2.begin();

  list_char.insert_many(it7, 'r', 'a', 'h', 'c');
  list_char2.insert_many(it8, 'c');

  for (s21::List<char>::iterator i = list_char.begin(), j = list_char2.begin(),
                                 k = check.begin();
       k != check.end(); ++i, ++j, ++k) {
    EXPECT_EQ(*i, *k);
    EXPECT_EQ(*j, *k);
    EXPECT_EQ(*i, *j);
  }

  // std::cout << "list_char:" << std::endl;
  // for (s21::List<char>::iterator i = list_char.begin(); i != list_char.end();
  // ++i) std::cout << *i << std::endl;

  // std::cout << std::endl;
  // std::cout << "list_char2:" << std::endl;
  // for (s21::List<char>::iterator i = list_char2.begin(); i !=
  // list_char2.end(); ++i) std::cout << *i << std::endl;
}

TEST(ListTest, Iterator_Insert_Many_Back) {
  // int
  s21::List<int> list_int;
  s21::List<int> list_int2{1, 2, 3};
  s21::List<int> check_int{1, 2, 3};
  s21::List<int> check_int2{1, 2, 3, 4, 5, 6};

  list_int.insert_many_back(1, 2, 3);
  list_int2.insert_many_back(4, 5, 6);

  // std::cout << list_int.front() << std::endl;
  // std::cout << list_int.back() << std::endl;

  for (s21::List<int>::iterator i = list_int.begin(), j = check_int.begin();
       i != list_int.end(); ++i, ++j)
    EXPECT_EQ(*i, *j);

  for (s21::List<int>::iterator i = list_int2.begin(), j = check_int2.begin();
       i != list_int2.end(); ++i, ++j)
    EXPECT_EQ(*i, *j);

  // // double
  s21::List<double> list_double;
  s21::List<double> list_double2{0.0, 2.0, 4.0};
  s21::List<double> check_double{1.0, 2.0, 3.0};
  s21::List<double> check_double2{0.0, 2.0, 4.0, 6.0, 8.0, 10.0};

  list_double.insert_many_back(1.0, 2.0, 3.0);
  list_double2.insert_many_back(6.0, 8.0, 10.0);

  for (s21::List<double>::iterator i = list_double.begin(),
                                   j = check_double.begin();
       i != list_double.end(); ++i, ++j)
    EXPECT_EQ(*i, *j);

  for (s21::List<double>::iterator i = list_double2.begin(),
                                   j = check_double2.begin();
       i != list_double2.end(); ++i, ++j)
    EXPECT_EQ(*i, *j);

  // // string
  s21::List<std::string> list_string;
  s21::List<std::string> list_string2{"queue", "list"};
  s21::List<std::string> check_string{"queue", "list",   "map",
                                      "set",   "vector", "array"};

  list_string.insert_many_back("queue", "list", "map", "set", "vector",
                               "array");
  list_string2.insert_many_back("map", "set", "vector", "array");

  for (s21::List<std::string>::iterator i = list_string.begin(),
                                        j = list_string2.begin(),
                                        k = check_string.begin();
       i != list_string.end(); ++i, ++j, ++k) {
    EXPECT_EQ(*i, *k);
    EXPECT_EQ(*j, *k);
    EXPECT_EQ(*i, *j);
  }

  // // char
  s21::List<char> list_char;
  s21::List<char> list_char2{'q', 'u'};
  s21::List<char> check_char{'q', 'u', 'e', 'u', 'e'};

  list_char.insert_many_back('q', 'u', 'e', 'u', 'e');
  list_char2.insert_many_back('e', 'u', 'e');

  for (s21::List<char>::iterator i = list_char.begin(), j = list_char2.begin(),
                                 k = check_char.begin();
       i != list_char.end(); ++i, ++j, ++k) {
    EXPECT_EQ(*i, *k);
    EXPECT_EQ(*j, *k);
    EXPECT_EQ(*i, *j);
  }
}

TEST(ListTest, Iterator_Insert_Many_Front) {
  // int
  s21::List<int> list_int;
  s21::List<int> list_int2{4, 5, 6};
  s21::List<int> check_int{1, 2, 3, 4, 5, 6};

  list_int.insert_many_front(6, 5, 4, 3, 2, 1);
  list_int2.insert_many_front(3, 2, 1);

  for (s21::List<int>::iterator i = list_int.begin(), j = list_int2.begin(),
                                k = check_int.begin();
       i != list_int.end(); ++i, ++j, ++k) {
    EXPECT_EQ(*i, *k);
    EXPECT_EQ(*j, *k);
    EXPECT_EQ(*i, *j);
  }

  // double
  s21::List<double> list_double;
  s21::List<double> list_double2{1.0, 9.0, 0.8};
  s21::List<double> check_double{10.0, 0.8, -19.0, 99.9, 1.0, 9.0, 0.8};

  list_double.insert_many_front(0.8, 9.0, 1.0, 99.9, -19.0, 0.8, 10.0);
  list_double2.insert_many_front(99.9, -19.0, 0.8, 10.0);

  for (s21::List<double>::iterator i = list_double.begin(),
                                   j = list_double2.begin(),
                                   k = check_double.begin();
       i != list_double.end(); ++i, ++j, ++k) {
    EXPECT_EQ(*i, *k);
    EXPECT_EQ(*j, *k);
    EXPECT_EQ(*i, *j);
  }

  // string
  s21::List<std::string> list_string;
  s21::List<std::string> list_string2{"vector", "array"};
  s21::List<std::string> check_string{"queue", "list",   "map",
                                      "set",   "vector", "array"};

  list_string.insert_many_front("array", "vector", "set", "map", "list",
                                "queue");
  list_string2.insert_many_front("set", "map", "list", "queue");

  for (s21::List<std::string>::iterator i = list_string.begin(),
                                        j = list_string2.begin(),
                                        k = check_string.begin();
       i != list_string.end(); ++i, ++j, ++k) {
    EXPECT_EQ(*i, *k);
    EXPECT_EQ(*j, *k);
    EXPECT_EQ(*i, *j);
  }

  // char
  s21::List<char> list_char;
  s21::List<char> list_char2{'u', 'e'};
  s21::List<char> check_char{'q', 'u', 'e', 'u', 'e'};

  list_char.insert_many_front('e', 'u', 'e', 'u', 'q');
  list_char2.insert_many_front('e', 'u', 'q');

  for (s21::List<char>::iterator i = list_char.begin(), j = list_char2.begin(),
                                 k = check_char.begin();
       i != list_char.end(); ++i, ++j, ++k) {
    EXPECT_EQ(*i, *k);
    EXPECT_EQ(*j, *k);
    EXPECT_EQ(*i, *j);
  }
}

///////////////
//    Set    //
///////////////

// Iterators

TEST(Test, set_iter_begin_1) {
  s21::Set<int> a = {1, 3, 2};
  std::set<int> b = {1, 3, 2};

  s21::Set<int>::iterator it1 = a.begin();
  std::set<int>::iterator it2 = b.begin();

  EXPECT_TRUE(*it1 == *it2);
}

TEST(Test, set_iter_begin_2) {
  s21::Set<int> a;
  std::set<int> b;

  EXPECT_TRUE(a.begin() == a.end() && b.begin() == b.end());
}

TEST(Test, set_iter_end_1) {
  s21::Set<int> a = {1, 3, 2};
  std::set<int> b = {1, 3, 2};

  s21::Set<int>::iterator it1 = a.end();
  std::set<int>::iterator it2 = b.end();

  EXPECT_TRUE(*(--it1) == *(--it2));
}

// Set Capacity

TEST(Test, set_empty_1) {
  s21::Set<double> a = {1, 2};
  std::set<double> b = {1, 2};

  EXPECT_TRUE(a.empty() == b.empty());
}

TEST(Test, set_empty_2) {
  s21::Set<double> a;
  std::set<double> b;

  EXPECT_TRUE(a.empty() == b.empty());
}

TEST(Test, set_size_1) {
  s21::Set<double> a;
  std::set<double> b;

  EXPECT_TRUE(a.size() == b.size());
}

TEST(Test, set_size_2) {
  s21::Set<double> a = {1, 2, 3, 4, 5, 9};
  std::set<double> b = {1, 2, 3, 4, 5, 9};

  EXPECT_TRUE(a.size() == b.size());
}

TEST(Test, set_max_size_1) {
  s21::Set<int> a;
  std::set<int> b;

  // std::cout << a.max_size() << std::endl;
  // std::cout << b.max_size() << std::endl;

  EXPECT_EQ(a.max_size(), b.max_size());
}

// Set Modifiers

TEST(Test, set_clear_1) {
  s21::Set<double> a = {1};
  std::set<double> b = {1, 2, 3, 4, 5, 6, 7};
  a.clear();
  b.clear();

  EXPECT_TRUE(a.empty() == b.empty());
}

TEST(Test, set_insert_1) {
  s21::Set<double> a = {1};
  std::set<double> b = {1};

  std::pair<s21::Set<double>::iterator, bool> res1 = a.insert(2);
  std::pair<std::set<double>::iterator, bool> res2 = b.insert(2);

  EXPECT_TRUE(*res1.first == *res2.first && res1.second == res2.second);
}

TEST(Test, set_insert_2) {
  s21::Set<double> a = {1};
  std::set<double> b = {1};

  std::pair<s21::Set<double>::iterator, bool> res1 = a.insert(1);
  std::pair<std::set<double>::iterator, bool> res2 = b.insert(1);

  EXPECT_TRUE(*res1.first == *res2.first && res1.second == res2.second);
}

TEST(Test, set_insert_many_1) {
  s21::Set<double> a = {1};

  std::vector<std::pair<s21::Set<double>::iterator, bool>> results =
      a.insert_many(-3, 0, 1, 0, 0);

  std::vector<bool> prov = {true, true, false, false, false};

  bool res = true;
  for (unsigned int i = 0; i < prov.size(); ++i) {
    if (prov[i] != results[i].second) {
      std::cout << results[i].second << std::endl;
      res = false;
    }
  }

  EXPECT_TRUE(res);
}

TEST(Test, set_erase_1) {
  s21::Set<double> a = {1, 2, -99, -3, -5, 4, 8, 2, 3};
  std::set<double> b = {1, 2, -99, -3, -5, 4, 8, 2, 3};

  a.erase(a.find(8));
  b.erase(b.find(8));

  s21::Set<double>::iterator it1 = a.begin();

  bool res = true;
  for (auto it = b.begin(); it != b.end(); ++it, ++it1) {
    if (*it != *it1) {
      res = false;
      break;
    }
  }
  EXPECT_TRUE(res);
}

TEST(Test, set_erase_2) {
  s21::Set<double> a = {-10, -8, -6, -4, -5, -1, -2, 0, 1, 3, 5, 7, 9, 10};
  std::set<double> b = {-10, -8, -6, -4, -5, -1, -2, 0, 1, 3, 5, 7, 9, 10};

  a.erase(a.find(-6));
  b.erase(b.find(-6));

  s21::Set<double>::iterator it1 = a.begin();

  bool res = true;
  for (auto it = b.begin(); it != b.end(); ++it, ++it1) {
    if (*it != *it1) {
      res = false;
      break;
    }
  }
  EXPECT_TRUE(res);
}

TEST(Test, set_erase_3) {
  s21::Set<double> a = {-10, -8, -6, -4, -5, -1, -2, 0, 1, 3, 5, 7, 9, 10};
  std::set<double> b = {-10, -8, -6, -4, -5, -1, -2, 0, 1, 3, 5, 7, 9, 10};

  a.erase(a.find(3));
  b.erase(b.find(3));

  s21::Set<double>::iterator it1 = a.begin();

  bool res = true;
  for (auto it = b.begin(); it != b.end(); ++it, ++it1) {
    if (*it != *it1) {
      res = false;
      break;
    }
  }
  EXPECT_TRUE(res);
}

// тест с утечкой
// TEST(Test, set_erase_4) {
//   s21::Set<double> a = {1, 2};
//   s21::Set<double>::iterator c = a.end();

//   ASSERT_THROW(a.erase(c), std::runtime_error);
// }

TEST(Test, set_swap_1) {
  s21::Set<double> a1 = {1, 2};
  s21::Set<double> a2 = {3, 4};

  a1.swap(a2);

  std::set<double> b1 = {1, 2};
  std::set<double> b2 = {3, 4};

  b1.swap(b2);

  EXPECT_TRUE(*a1.begin() == 3 && *a2.begin() == 1 && *b1.begin() == 3 &&
              *b2.begin() == 1);
}

TEST(Test, set_merge_1) {
  s21::Set<double> a1 = {1, 2};
  s21::Set<double> a2 = {3, 4};

  a1.merge(a2);

  std::set<double> b1 = {1, 2};
  std::set<double> b2 = {3, 4};

  b1.merge(b2);

  s21::Set<double>::iterator it1 = a1.begin();

  bool res = true;
  for (auto it = b1.begin(); it != b1.end(); ++it, ++it1) {
    if (*it != *it1) {
      res = false;
      break;
    }
  }
  EXPECT_TRUE(res);
}

// Set Lookup

TEST(Test, set_find_1) {
  s21::Set<double> a = {1, 2};
  std::set<double> b = {1, 2};

  s21::Set<double>::iterator it1 = a.find(2);
  std::set<double>::iterator it2 = b.find(2);

  EXPECT_TRUE(*it1 == *it2);
}

TEST(Test, set_contains_1) {
  s21::Set<double> a = {0};

  EXPECT_TRUE(a.contains(0));
}

TEST(Test, set_contains_2) {
  s21::Set<double> a = {0};

  EXPECT_FALSE(a.contains(1));
}

//////////////
// multiset //
//////////////

// Multiset Member functions

TEST(Test, multiset_contructor_1) {
  s21::Multiset<int> a = {1, 1, 1};
  std::multiset<int> b = {1, 1, 1};

  EXPECT_TRUE(a.size() == b.size());
}

TEST(Test, multiset_contructor_2) {
  s21::Multiset<int> a1 = {1, 4, 5};
  s21::Multiset<int> a2 = a1;

  std::multiset<int> b1 = {1, 4, 5};
  std::multiset<int> b2 = b1;

  EXPECT_TRUE(a2.size() == b2.size());
}

TEST(Test, multiset_contructor_3) {
  s21::Multiset<int> a1 = {1, 4, 5};
  s21::Multiset<int> a2 = std::move(a1);

  std::multiset<int> b1 = {1, 4, 5};
  std::multiset<int> b2 = std::move(b1);

  EXPECT_TRUE(a2.size() == b2.size());
}

// Multiset Iterators

TEST(Test, multiset_begin_1) {
  s21::Multiset<int> a = {1, 1, 1};
  std::multiset<int> b = {1, 1, 1};

  EXPECT_TRUE(*a.begin() == *b.begin());
}

TEST(Test, multiset_end_1) {
  s21::Multiset<int> a = {1, 1, 1};
  std::multiset<int> b = {1, 1, 1};

  EXPECT_TRUE(*(--a.end()) == *(--b.end()));
}

TEST(Test, multiset_empty_1) {
  s21::Multiset<int> a;
  std::multiset<int> b;

  EXPECT_TRUE(a.empty() == b.empty());
}

TEST(Test, multiset_empty_2) {
  s21::Multiset<int> a = {1, 1};
  std::multiset<int> b = {1, 1};

  EXPECT_TRUE(a.empty() == b.empty());
}

TEST(Test, multiset_size_1) {
  s21::Multiset<int> a = {1, 1};
  std::multiset<int> b = {1, 1};

  EXPECT_TRUE(a.size() == b.size());
}

TEST(Test, multiset_size_2) {
  s21::Multiset<int> a;
  std::multiset<int> b;

  EXPECT_TRUE(a.size() == b.size());
}

TEST(Test, multiset_max_size_1) {
  s21::Multiset<int> a;
  std::multiset<int> b;

  EXPECT_TRUE(true);

  EXPECT_EQ(a.max_size(), b.max_size());
}

// Multiset Modifiers

TEST(Test, multiset_clear_1) {
  s21::Multiset<int> a;
  std::multiset<int> b;

  a.clear();
  b.clear();

  EXPECT_TRUE(a.size() == b.size());
}

TEST(Test, multiset_clear_2) {
  s21::Multiset<int> a = {1, 2, 3};
  std::multiset<int> b;

  a.clear();
  b.clear();

  EXPECT_TRUE(a.size() == b.size());
}

TEST(Test, multiset_insert_1) {
  s21::Multiset<double> a = {1, 9};
  std::multiset<double> b = {1, 9};

  s21::Multiset<double>::iterator res1 = a.insert(1);
  std::multiset<double>::iterator res2 = b.insert(1);

  EXPECT_TRUE(*res1 == *res2);
}

TEST(Test, multiset_insert_2) {
  s21::Multiset<double> a;
  std::multiset<double> b;

  s21::Multiset<double>::iterator res1 = a.insert(1);
  std::multiset<double>::iterator res2 = b.insert(1);

  EXPECT_TRUE(*res1 == *res2);
}

TEST(Test, multiset_insert_many_1) {
  s21::Multiset<double> a = {1};

  s21::Vector<std::pair<s21::Multiset<double>::iterator, bool>> results =
      a.insert_many(-3, 0, 1, 0, 0);

  s21::Vector<bool> prov = {true, true, false, false, false};

  bool res = true;
  for (unsigned int i = 0; i < prov.size(); ++i) {
    if (prov[i] != results[i].second) {
      std::cout << results[i].second << std::endl;
      res = false;
    }
  }

  EXPECT_TRUE(res);
}

TEST(Test, multiset_erase_1) {
  s21::Multiset<double> a = {1, 0};
  std::multiset<double> b = {1, 0};

  s21::Multiset<double>::iterator c1 = a.begin();
  std::multiset<double>::iterator c2 = b.begin();

  a.erase(c1);
  b.erase(c2);

  EXPECT_TRUE(*a.begin() == *b.begin());
}

TEST(Test, multiset_swap_1) {
  s21::Multiset<double> a1 = {3, 2, 1};
  s21::Multiset<double> a2 = {0};
  std::multiset<double> b1 = {3, 2, 1};
  std::multiset<double> b2 = {0};

  a1.swap(a2);
  b1.swap(b2);

  EXPECT_TRUE(a1.size() == b1.size() && a2.size() == b2.size());
}

TEST(Test, multiset_merge_1) {
  s21::Multiset<double> a1 = {3, 2, 1};
  s21::Multiset<double> a2 = {0};
  std::multiset<double> b1 = {3, 2, 1};
  std::multiset<double> b2 = {0};

  a1.merge(a2);
  b1.merge(b2);

  EXPECT_TRUE(a1.size() == b1.size());
}

// Multiset Lookup

TEST(Test, multiset_count_1) {
  s21::Multiset<int> a = {1, 1, 1};
  std::multiset<int> b = {1, 1, 1};

  EXPECT_TRUE(a.count(1) == b.count(1));
}

TEST(Test, multiset_find_1) {
  s21::Multiset<int> a = {1, 1, 1, 2};
  std::multiset<int> b = {1, 1, 1, 2};

  EXPECT_TRUE(*(++a.find(1)) == *(++b.find(1)));
}

TEST(Test, multiset_contains_1) {
  s21::Multiset<int> a = {1, 1, 1, 2};

  EXPECT_TRUE(a.contains(3) == false);
}

TEST(Test, multiset_contains_2) {
  s21::Multiset<int> a = {1, 1, 1, 2};

  EXPECT_TRUE(a.contains(1) == true);
}

TEST(Test, multiset_equal_range_1) {
  s21::Multiset<int> a = {-1, 1, 1, 1, 2};

  std::multiset<int> b = {-1, 1, 1, 1, 2};

  std::pair<s21::Multiset<int>::iterator, s21::Multiset<int>::iterator>
      result1 = a.equal_range(1);
  std::pair<std::multiset<int>::iterator, std::multiset<int>::iterator>
      result2 = b.equal_range(1);

  EXPECT_TRUE(*(--result1.first) == *(--result2.first) &&
              *(result1.second) == *(result2.second));
}

TEST(Test, multiset_equal_range_2) {
  s21::Multiset<int> a = {1, 2, 3, 4, 5};

  std::multiset<int> b = {1, 2, 3, 4, 5};

  std::pair<s21::Multiset<int>::iterator, s21::Multiset<int>::iterator>
      result1 = a.equal_range(-2);

  std::pair<std::multiset<int>::iterator, std::multiset<int>::iterator>
      result2 = b.equal_range(-2);

  EXPECT_TRUE(result2.first == result2.second &&
              result1.first == result1.second);
}

TEST(Test, multiset_lower_bound_1) {
  s21::Multiset<int> a = {1, 1, 3, 4, 5};
  std::multiset<int> b = {1, 1, 3, 4, 5};

  s21::Multiset<int>::iterator result1 = a.lower_bound(1);
  std::multiset<int>::iterator result2 = b.lower_bound(1);

  EXPECT_TRUE(*(++(++result1)) == *(++(++result2)));
}

TEST(Test, multiset_upper_bound_1) {
  s21::Multiset<int> a = {1, 1, 3, 4, 5};
  std::multiset<int> b = {1, 1, 3, 4, 5};

  EXPECT_TRUE(*a.upper_bound(1) == *b.upper_bound(1));
}

TEST(Test, multiset_upper_bound_2) {
  s21::Multiset<int> a;
  std::multiset<int> b;

  EXPECT_TRUE(a.upper_bound(1) == a.end() && b.upper_bound(1) == b.end());
}

///////////////////
//     Queue     //
///////////////////

// Constructors

TEST(QueueTest, Default_Constructor) {
  s21::Queue<int> my_queue;
  std::queue<int> std_queue;

  EXPECT_EQ(my_queue.size(), 0);
  EXPECT_EQ(my_queue.size(), std_queue.size());
}

TEST(QueueTest, Param_Constructor) {
  s21::Queue<int> queue_int{1, 2, 3, 4, 5, 6, 7};
  s21::Queue<double> queue_double{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
  s21::Queue<std::string> queue_string{"My", "name", "is", "Kseniya"};
  s21::Queue<char> queue_char{'H', 'e', 'l', 'l', 'o'};

  std::deque<int> deque_int{1, 2, 3, 4, 5, 6, 7};
  std::queue<int> std_int(deque_int);

  std::deque<double> deque_double{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
  std::queue<double> std_double(deque_double);

  std::deque<std::string> deque_string{"My", "name", "is", "Kseniya"};
  std::queue<std::string> std_string(deque_string);

  std::deque<char> deque_char{'H', 'e', 'l', 'l', 'o'};
  std::queue<char> std_char(deque_char);

  EXPECT_EQ(queue_int.size(), 7);
  EXPECT_EQ(std_int.size(), 7);
  EXPECT_EQ(queue_int.size(), std_int.size());
  EXPECT_EQ(queue_int.front(), std_int.front());
  EXPECT_EQ(queue_int.back(), std_int.back());

  EXPECT_EQ(queue_double.size(), 7);
  EXPECT_EQ(std_double.size(), 7);
  EXPECT_EQ(queue_double.size(), std_double.size());
  EXPECT_EQ(queue_double.front(), std_double.front());
  EXPECT_EQ(queue_double.back(), std_double.back());

  EXPECT_EQ(queue_string.size(), 4);
  EXPECT_EQ(std_string.size(), 4);
  EXPECT_EQ(queue_string.size(), std_string.size());
  EXPECT_EQ(queue_string.front(), std_string.front());
  EXPECT_EQ(queue_string.back(), std_string.back());

  EXPECT_EQ(queue_char.size(), 5);
  EXPECT_EQ(std_char.size(), 5);
  EXPECT_EQ(queue_char.size(), std_char.size());
  EXPECT_EQ(queue_char.front(), std_char.front());
  EXPECT_EQ(queue_char.back(), std_char.back());
}

TEST(QueueTest, Copy_Constructor) {
  // наш контейнер
  s21::Queue<int> queue_int{1, 2, 3, 4, 5, 6, 7};
  s21::Queue<int> copy_int(queue_int);

  s21::Queue<double> queue_double{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
  s21::Queue<double> copy_double(queue_double);

  s21::Queue<std::string> queue_string{"My", "name", "is", "Kseniya"};
  s21::Queue<std::string> copy_string(queue_string);

  s21::Queue<char> queue_char{'H', 'e', 'l', 'l', 'o'};
  s21::Queue<char> copy_char(queue_char);

  //  стандартный контейнер
  std::deque<int> deque_int{1, 2, 3, 4, 5, 6, 7};
  std::queue<int> std_int(deque_int);
  std::queue<int> std_int2(std_int);

  std::deque<double> deque_double{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
  std::queue<double> std_double(deque_double);
  std::queue<double> std_double2(std_double);

  std::deque<std::string> deque_string{"My", "name", "is", "Kseniya"};
  std::queue<std::string> std_string(deque_string);
  std::queue<std::string> std_string2(std_string);

  std::deque<char> deque_char{'H', 'e', 'l', 'l', 'o'};
  std::queue<char> std_char(deque_char);
  std::queue<char> std_char2(std_char);

  EXPECT_EQ(queue_int.front(), copy_int.front());
  EXPECT_EQ(queue_int.back(), copy_int.back());
  EXPECT_EQ(copy_int.front(), std_int2.front());
  EXPECT_EQ(copy_int.back(), std_int2.back());
  EXPECT_EQ(copy_int.size(), std_int2.size());

  EXPECT_EQ(queue_double.front(), copy_double.front());
  EXPECT_EQ(queue_double.back(), copy_double.back());
  EXPECT_EQ(copy_double.front(), std_double2.front());
  EXPECT_EQ(copy_double.back(), std_double2.back());
  EXPECT_EQ(copy_double.size(), std_double2.size());

  EXPECT_EQ(queue_string.front(), copy_string.front());
  EXPECT_EQ(queue_string.back(), copy_string.back());
  EXPECT_EQ(copy_string.front(), std_string2.front());
  EXPECT_EQ(copy_string.back(), std_string2.back());
  EXPECT_EQ(copy_string.size(), std_string2.size());

  EXPECT_EQ(queue_char.front(), copy_char.front());
  EXPECT_EQ(queue_char.back(), copy_char.back());
  EXPECT_EQ(copy_char.front(), std_char2.front());
  EXPECT_EQ(copy_char.back(), std_char2.back());
  EXPECT_EQ(copy_char.size(), std_char2.size());
}

TEST(QueueTest, Move_Constructor) {
  // наш контейнер
  s21::Queue<int> queue_int{1, 2, 3, 4, 5, 6, 7};
  s21::Queue<int> move_int(std::move(queue_int));

  s21::Queue<double> queue_double{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
  s21::Queue<double> move_double(std::move(queue_double));

  s21::Queue<std::string> queue_string{"My", "name", "is", "Kseniya"};
  s21::Queue<std::string> move_string(std::move(queue_string));

  s21::Queue<char> queue_char{'H', 'e', 'l', 'l', 'o'};
  s21::Queue<char> move_char(std::move(queue_char));

  //  стандартный контейнер
  std::deque<int> deque_int{1, 2, 3, 4, 5, 6, 7};
  std::queue<int> std_int(deque_int);
  std::queue<int> std_int2(std::move(std_int));

  std::deque<double> deque_double{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
  std::queue<double> std_double(deque_double);
  std::queue<double> std_double2(std::move(std_double));

  std::deque<std::string> deque_string{"My", "name", "is", "Kseniya"};
  std::queue<std::string> std_string(deque_string);
  std::queue<std::string> std_string2(std::move(std_string));

  std::deque<char> deque_char{'H', 'e', 'l', 'l', 'o'};
  std::queue<char> std_char(deque_char);
  std::queue<char> std_char2(std::move(std_char));

  EXPECT_EQ(queue_int.size(), 0U);
  EXPECT_EQ(std_int.size(), 0U);
  EXPECT_EQ(move_int.front(), std_int2.front());
  EXPECT_EQ(move_int.back(), std_int2.back());
  EXPECT_EQ(move_int.size(), std_int2.size());

  EXPECT_EQ(queue_double.size(), 0U);
  EXPECT_EQ(std_double.size(), 0U);
  EXPECT_EQ(move_double.front(), std_double2.front());
  EXPECT_EQ(move_double.back(), std_double2.back());
  EXPECT_EQ(move_double.size(), std_double2.size());

  EXPECT_EQ(queue_string.size(), 0U);
  EXPECT_EQ(std_string.size(), 0U);
  EXPECT_EQ(move_string.front(), std_string2.front());
  EXPECT_EQ(move_string.back(), std_string2.back());
  EXPECT_EQ(move_string.size(), std_string2.size());

  EXPECT_EQ(queue_char.size(), 0U);
  EXPECT_EQ(std_char.size(), 0U);
  EXPECT_EQ(move_char.front(), std_char2.front());
  EXPECT_EQ(move_char.back(), std_char2.back());
  EXPECT_EQ(move_char.size(), std_char2.size());
}

TEST(QueueTest, Copy_Assign) {
  // наш контейнер
  s21::Queue<int> queue_int{0, 2, 4, 1, 5, 5, 6};
  s21::Queue<int> copy_int = queue_int;

  s21::Queue<double> queue_double{0.0, 8.0, 3.4, 728.9, 288.9};
  s21::Queue<double> copy_double = queue_double;

  s21::Queue<std::string> queue_string{"You", "don't", "own", "me"};
  s21::Queue<std::string> copy_string = queue_string;

  s21::Queue<char> queue_char{'H', 'e', 'l', 'l', 'o'};
  s21::Queue<char> copy_char = queue_char;

  //  стандартный контейнер
  std::deque<int> deque_int{0, 2, 4, 1, 5, 5, 6};
  std::queue<int> std_int(deque_int);
  std::queue<int> std_int2 = std_int;

  std::deque<double> deque_double{0.0, 8.0, 3.4, 728.9, 288.9};
  std::queue<double> std_double(deque_double);
  std::queue<double> std_double2 = std_double;

  std::deque<std::string> deque_string{"You", "don't", "own", "me"};
  std::queue<std::string> std_string(deque_string);
  std::queue<std::string> std_string2 = std_string;

  std::deque<char> deque_char{'H', 'e', 'l', 'l', 'o'};
  std::queue<char> std_char(deque_char);
  std::queue<char> std_char2 = std_char;

  EXPECT_EQ(queue_int.front(), copy_int.front());
  EXPECT_EQ(queue_int.back(), copy_int.back());
  EXPECT_EQ(copy_int.front(), std_int2.front());
  EXPECT_EQ(copy_int.back(), std_int2.back());
  EXPECT_EQ(copy_int.size(), std_int2.size());

  EXPECT_EQ(queue_double.front(), copy_double.front());
  EXPECT_EQ(queue_double.back(), copy_double.back());
  EXPECT_EQ(copy_double.front(), std_double2.front());
  EXPECT_EQ(copy_double.back(), std_double2.back());
  EXPECT_EQ(copy_double.size(), std_double2.size());

  EXPECT_EQ(queue_string.front(), copy_string.front());
  EXPECT_EQ(queue_string.back(), copy_string.back());
  EXPECT_EQ(copy_string.front(), std_string2.front());
  EXPECT_EQ(copy_string.back(), std_string2.back());
  EXPECT_EQ(copy_string.size(), std_string2.size());

  EXPECT_EQ(queue_char.front(), copy_char.front());
  EXPECT_EQ(queue_char.back(), copy_char.back());
  EXPECT_EQ(copy_char.front(), std_char2.front());
  EXPECT_EQ(copy_char.back(), std_char2.back());
  EXPECT_EQ(copy_char.size(), std_char2.size());
}

TEST(QueueTest, Move_Assign) {
  // наш контейнер
  s21::Queue<int> queue_int{200, 9, 88, 27, -9, -19};
  s21::Queue<int> move_int = std::move(queue_int);

  s21::Queue<double> queue_double{144.0, -2.0, 3.0, 78.0, -0.8, 6.0, 7.0};
  s21::Queue<double> move_double = std::move(queue_double);

  s21::Queue<std::string> queue_string{"Faber", "Castle"};
  s21::Queue<std::string> move_string = std::move(queue_string);

  s21::Queue<char> queue_char{'q', 'u', 'e', 'u', 'e'};
  s21::Queue<char> move_char = std::move(queue_char);

  //  стандартный контейнер
  std::deque<int> deque_int{200, 9, 88, 27, -9, -19};
  std::queue<int> std_int(deque_int);
  std::queue<int> std_int2 = std::move(std_int);

  std::deque<double> deque_double{144.0, -2.0, 3.0, 78.0, -0.8, 6.0, 7.0};
  std::queue<double> std_double(deque_double);
  std::queue<double> std_double2 = std::move(std_double);

  std::deque<std::string> deque_string{"Faber", "Castle"};
  std::queue<std::string> std_string(deque_string);
  std::queue<std::string> std_string2 = std::move(std_string);

  std::deque<char> deque_char{'q', 'u', 'e', 'u', 'e'};
  std::queue<char> std_char(deque_char);
  std::queue<char> std_char2 = std::move(std_char);

  EXPECT_EQ(queue_int.size(), 0U);
  EXPECT_EQ(std_int.size(), 0U);
  EXPECT_EQ(move_int.front(), std_int2.front());
  EXPECT_EQ(move_int.back(), std_int2.back());
  EXPECT_EQ(move_int.size(), std_int2.size());

  EXPECT_EQ(queue_double.size(), 0U);
  EXPECT_EQ(std_double.size(), 0U);
  EXPECT_EQ(move_double.front(), std_double2.front());
  EXPECT_EQ(move_double.back(), std_double2.back());
  EXPECT_EQ(move_double.size(), std_double2.size());

  EXPECT_EQ(queue_string.size(), 0U);
  EXPECT_EQ(std_string.size(), 0U);
  EXPECT_EQ(move_string.front(), std_string2.front());
  EXPECT_EQ(move_string.back(), std_string2.back());
  EXPECT_EQ(move_string.size(), std_string2.size());

  EXPECT_EQ(queue_char.size(), 0U);
  EXPECT_EQ(std_char.size(), 0U);
  EXPECT_EQ(move_char.front(), std_char2.front());
  EXPECT_EQ(move_char.back(), std_char2.back());
  EXPECT_EQ(move_char.size(), std_char2.size());
}

TEST(QueueTest, Push) {
  // наш контейнер
  s21::Queue<int> queue_int;
  s21::Queue<int> queue_int2{29, 0, 19, 4, 10, 1, -10};

  queue_int.push(9);
  queue_int.push(-19);
  queue_int2.push(9);
  queue_int2.push(-19);

  s21::Queue<double> queue_double;
  s21::Queue<double> queue_double2{-0.8, 91.0, -0.9, 10.9, 2.7, 3.0};

  queue_double.push(10.0);
  queue_double.push(-10.0);
  queue_double2.push(10.0);
  queue_double2.push(-10.0);

  s21::Queue<std::string> queue_string;
  s21::Queue<std::string> queue_string2{"container", "queue"};

  queue_string.push("the");
  queue_string.push("best");
  queue_string2.push("the");
  queue_string2.push("best");

  s21::Queue<char> queue_char;
  s21::Queue<char> queue_char2{'i', 'c', 'e', 'b', 'e', 'r', 'g'};

  queue_char.push('a');
  queue_char.push('a');
  queue_char2.push('a');
  queue_char2.push('a');

  // стандартный контейнер
  std::deque<int> deque_int{29, 0, 19, 4, 10, 1, -10};
  std::queue<int> std_int(deque_int);
  std::queue<int> std_int2;

  std_int.push(9);
  std_int.push(-19);
  std_int2.push(9);
  std_int2.push(-19);

  std::deque<double> deque_double{-0.8, 91.0, -0.9, 10.9, 2.7, 3.0};
  std::queue<double> std_double(deque_double);
  std::queue<double> std_double2;

  std_double.push(10.0);
  std_double.push(-10.0);
  std_double2.push(10.0);
  std_double2.push(-10.0);

  std::deque<std::string> deque_string{"container", "queue"};
  std::queue<std::string> std_string(deque_string);
  std::queue<std::string> std_string2;

  std_string.push("the");
  std_string.push("best");
  std_string2.push("the");
  std_string2.push("best");

  std::deque<char> deque_char{'i', 'c', 'e'};
  std::queue<char> std_char(deque_char);
  std::queue<char> std_char2;

  std_char.push('a');
  std_char.push('a');
  std_char2.push('a');
  std_char2.push('a');

  EXPECT_EQ(queue_int.back(), std_int.back());
  EXPECT_EQ(queue_int.back(), queue_int2.back());
  EXPECT_EQ(queue_int.back(), -19);
  EXPECT_EQ(queue_int2.back(), std_int2.back());
  EXPECT_EQ(queue_int2.back(), -19);

  EXPECT_EQ(queue_double.back(), std_double.back());
  EXPECT_EQ(queue_double.back(), queue_double2.back());
  EXPECT_EQ(queue_double.back(), -10.0);
  EXPECT_EQ(queue_double2.back(), std_double2.back());
  EXPECT_EQ(queue_double2.back(), -10.0);

  EXPECT_EQ(queue_string.back(), std_string.back());
  EXPECT_EQ(queue_string.back(), queue_string2.back());
  EXPECT_EQ(queue_string.back(), "best");
  EXPECT_EQ(queue_string2.back(), std_string2.back());
  EXPECT_EQ(queue_string2.back(), "best");

  EXPECT_EQ(queue_char.back(), std_char.back());
  EXPECT_EQ(queue_char.back(), queue_char2.back());
  EXPECT_EQ(queue_char.back(), 'a');
  EXPECT_EQ(queue_char2.back(), std_char2.back());
  EXPECT_EQ(queue_char2.back(), 'a');
}

TEST(QueueTest, Pop) {
  // int
  s21::Queue<int> queue_int;
  std::queue<int> std_int;

  for (int i = 0; i < 8; ++i) {
    queue_int.push(i);
    std_int.push(i);
  }

  // std::cout << std_int.back() << std::endl;
  EXPECT_EQ(queue_int.size(), std_int.size());
  EXPECT_EQ(queue_int.front(), std_int.front());
  EXPECT_EQ(queue_int.back(), std_int.back());

  for (int i = 8; i != 0; --i) {
    std_int.pop();
    queue_int.pop();
  }

  EXPECT_EQ(queue_int.size(), std_int.size());
  EXPECT_EQ(queue_int.empty(), std_int.empty());
  // std::cout << std_int.size() << std::endl;
  // std::cout << queue_int.size() << std::endl;

  // double
  s21::Queue<int> queue_double;
  std::queue<int> std_double;
  for (int i = 0; i < 8; ++i) {
    queue_double.push(1.0);
    std_double.push(1.0);
  }

  EXPECT_EQ(queue_double.size(), std_double.size());
  EXPECT_EQ(queue_double.front(), std_double.front());
  EXPECT_EQ(queue_double.back(), std_double.back());

  for (int i = 0; i < 8; ++i) {
    queue_double.pop();
    std_double.pop();
  }

  EXPECT_EQ(queue_double.size(), std_double.size());
  EXPECT_EQ(queue_double.empty(), std_double.empty());

  // string
  s21::Queue<std::string> queue_string;
  std::queue<std::string> std_string;

  for (int i = 0; i < 8; ++i) {
    queue_string.push("hi");
    std_string.push("hi");
  }

  EXPECT_EQ(queue_string.size(), std_string.size());
  EXPECT_EQ(queue_string.front(), std_string.front());
  EXPECT_EQ(queue_string.back(), std_string.back());

  for (int i = 0; i < 8; ++i) {
    queue_string.pop();
    std_string.pop();
  }

  EXPECT_EQ(queue_string.size(), std_string.size());
  EXPECT_EQ(queue_string.empty(), std_string.empty());

  // char
  s21::Queue<char> queue_char;
  std::queue<char> std_char;

  for (int i = 0; i < 8; ++i) {
    queue_char.push('a');
    std_char.push('a');
  }

  EXPECT_EQ(queue_char.size(), std_char.size());
  EXPECT_EQ(queue_char.front(), std_char.front());
  EXPECT_EQ(queue_char.back(), std_char.back());

  for (int i = 0; i < 8; ++i) {
    queue_char.pop();
    std_char.pop();
  }

  EXPECT_EQ(queue_char.size(), std_char.size());
  EXPECT_EQ(queue_char.empty(), std_char.empty());
}

TEST(QueueTest, Insert_Many_Back) {
  // int
  s21::Queue<int> queue_int;
  s21::Queue<int> queue_int2{1, 2, 3};
  s21::Queue<int> check_int{1, 2, 3, 4, 5, 6};

  queue_int.insert_many_back(1, 2, 3, 4, 5, 6);
  queue_int2.insert_many_back(4, 5, 6);

  EXPECT_EQ(queue_int.front(), check_int.front());
  EXPECT_EQ(queue_int.back(), check_int.back());
  EXPECT_EQ(queue_int.size(), check_int.size());
  EXPECT_EQ(queue_int2.front(), check_int.front());
  EXPECT_EQ(queue_int2.back(), check_int.back());
  EXPECT_EQ(queue_int2.size(), check_int.size());
}

/////////////////////
//      Stack      //
/////////////////////

TEST(Test, test1) {
  s21::Stack<int> s21_stack;
  std::stack<int> std_stack;
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(Test, test2) {
  s21::Stack<int> s21_stack{1, 2, 3};
  EXPECT_EQ(s21_stack.size(), 3);
  EXPECT_EQ(s21_stack.top(), 3);
}

TEST(Test, test3) {
  std::initializer_list<int> a;
  s21::Stack<int> s21_stack{a};
  std::stack<int> std_stack{a};
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(Test, test4) {
  std::initializer_list<int> a = {1, 2, 3};

  s21::Stack<int> s21_stack{a};
  s21::Stack<int> s21_stack_copy{s21_stack};

  std::stack<int> std_stack{a};
  std::stack<int> std_stack_copy{std_stack};
  EXPECT_EQ(s21_stack_copy.size(), std_stack_copy.size());
  EXPECT_EQ(s21_stack_copy.top(), std_stack_copy.top());
}

TEST(Test, test5) {
  std::initializer_list<int> a = {1, 2, 3};

  s21::Stack<int> s21_stack{a};
  s21::Stack<int> s21_stack_move{s21_stack};
  std::stack<int> std_stack{a};
  std::stack<int> std_stack_move{std_stack};
  EXPECT_EQ(s21_stack_move.size(), std_stack_move.size());
  EXPECT_EQ(s21_stack_move.top(), std_stack_move.top());
}

TEST(Test, test6) {
  std::initializer_list<int> a1 = {1, 2, 3};
  std::initializer_list<int> a2 = {4, 5, 6, 7};

  s21::Stack<int> s21_stack{a1};
  s21::Stack<int> s21_stack_move{a2};
  s21_stack = std::move(s21_stack_move);

  std::stack<int> std_stack{a1};
  std::stack<int> std_stack_move{a2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(Test, test7) {
  std::initializer_list<int> a1 = {4, 5, 6, 7};
  std::initializer_list<int> a2 = {1, 2, 3};

  s21::Stack<int> s21_stack{a1};
  s21::Stack<int> s21_stack_move{a2};
  s21_stack = std::move(s21_stack_move);

  std::stack<int> std_stack{a1};
  std::stack<int> std_stack_move{a2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(Test, test8) {
  std::initializer_list<int> a1;
  std::initializer_list<int> a2 = {4, 5, 6, 7};

  s21::Stack<int> s21_stack{a1};
  s21::Stack<int> s21_stack_move{a2};
  s21_stack = std::move(s21_stack_move);

  std::stack<int> std_stack{a1};
  std::stack<int> std_stack_move{a2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(Test, test9) {
  std::initializer_list<int> a1 = {4, 5, 6, 7};

  s21::Stack<int> s21_stack{a1};

  std::stack<int> std_stack{a1};

  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

// тест с утечкой на exception
// TEST(Test, test10) {
//   std::initializer_list<int> a1;

//   s21::Stack<int> s21_stack{a1};

//   EXPECT_THROW(s21_stack.top(), std::out_of_range);
// }

TEST(Test, test11) {
  std::initializer_list<int> a1 = {4, 5, 6, 7};

  s21::Stack<int> s21_stack{a1};
  std::stack<int> std_stack{a1};

  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(Test, test12) {
  std::initializer_list<int> a1;

  s21::Stack<int> s21_stack{a1};
  std::stack<int> std_stack{a1};

  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(Test, test13) {
  std::initializer_list<int> a1 = {4, 5, 6, 7};

  s21::Stack<int> s21_stack{a1};
  std::stack<int> std_stack{a1};

  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(Test, test14) {
  std::initializer_list<int> a = {4, 5, 6, 7};

  s21::Stack<int> s21_stack{a};
  std::stack<int> std_stack{a};

  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(Test, test15) {
  std::initializer_list<int> a1 = {4, 5, 6, 7};

  s21::Stack<int> s21_stack{a1};
  std::stack<int> std_stack{a1};
  s21_stack.push(1);
  std_stack.push(1);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(Test, test17) {
  std::initializer_list<int> a1;

  s21::Stack<int> s21_stack{a1};
  std::stack<int> std_stack{a1};
  s21_stack.push(1);
  std_stack.push(1);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(Test, test18) {
  std::initializer_list<int> a1 = {4, 5, 6, 7};

  s21::Stack<int> s21_stack{a1};
  std::stack<int> std_stack{a1};
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(Test, test19) {
  std::initializer_list<int> a1;

  s21::Stack<int> s21_stack{a1};
  std::stack<int> std_stack{a1};
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.size(), 0);
}

TEST(Test, test20) {
  std::initializer_list<int> a1 = {4, 5, 6, 7};
  std::initializer_list<int> a2 = {1, 2, 3};

  s21::Stack<int> s21_stack{a1};
  s21::Stack<int> s21_stack_swap{a2};
  std::stack<int> std_stack{a1};
  std::stack<int> std_stack_swap{a2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(s21_stack_swap.top(), std_stack_swap.top());
}

TEST(Test, 21) {
  std::initializer_list<int> a1 = {1, 2, 3};
  std::initializer_list<int> a2 = {4, 5, 6, 7};

  s21::Stack<int> s21_stack{a1};
  s21::Stack<int> s21_stack_swap{a2};
  std::stack<int> std_stack{a1};
  std::stack<int> std_stack_swap{a2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(s21_stack_swap.top(), std_stack_swap.top());
}

TEST(Test, test22) {
  std::initializer_list<int> a1 = {4, 5, 6, 7};
  std::initializer_list<int> a2;

  s21::Stack<int> s21_stack{a1};
  s21::Stack<int> s21_stack_swap{a2};
  std::stack<int> std_stack{a1};
  std::stack<int> std_stack_swap{a2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
}

TEST(Test, Swap_4) {
  std::initializer_list<int> a1;
  std::initializer_list<int> a2 = {4, 5, 6, 7};

  s21::Stack<int> s21_stack{a1};
  s21::Stack<int> s21_stack_swap{a2};
  std::stack<int> std_stack{a1};
  std::stack<int> std_stack_swap{a2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
}

/////////////////////
//     Vector      //
/////////////////////

TEST(Vect_test, test1) {
  s21::Vector<int> s21_v;
  EXPECT_EQ(s21_v.capacity(), 0);
  EXPECT_EQ(s21_v.size(), 0);
  EXPECT_EQ(s21_v.data(), nullptr);
}

TEST(Vect_test, test2) {
  s21::Vector<int> v = {};

  EXPECT_EQ(v.size(), 0);
  EXPECT_EQ(v.capacity(), 0);
}

TEST(Vect_test, test3) {
  s21::Vector<int> s21_v(3);
  EXPECT_EQ(s21_v.size(), 3);
  EXPECT_EQ(s21_v.capacity(), 3);
}

TEST(Vect_Test, test4) {
  s21::Vector<int> s21_v = {1, 2, 3, 4, 5};
  std::vector<int> v = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(s21_v[i], v[i]);
  }
}

TEST(VECT_test, test5) {
  s21::Vector<char> s21_v = {1, 2, 3, 4};
  std::vector<char> v = {1, 2, 3, 4};
  s21_v.push_back(0);
  v.push_back(0);
  for (size_t i = 0; i < 5; i++) {
    EXPECT_EQ(s21_v[i], v[i]);
  }
}

TEST(VECT_test, test6) {
  s21::Vector<char> s21_v = {1, 2, 3, 4};
  for (size_t i = 0; i < 5; i++) {
    s21_v.pop_back();
  }
  EXPECT_TRUE(s21_v.empty());
}

TEST(VECT_test, test7) {
  s21::Vector<char> s21_v = {1, 2, 3, 4};
  std::vector<char> v = {};

  for (size_t i = 0; i < 5; i++) {
    s21_v.pop_back();
  }
  EXPECT_EQ(s21_v.empty(), v.empty());
  EXPECT_TRUE(s21_v.empty());
}

TEST(VECT_test, test8) {
  s21::Vector<char> s21_v = {1, 2, 3, 4};
  s21::Vector<char> s21_v1 = {};
  s21_v1 = s21_v;
  for (size_t i = 0; i < 4; i++) {
    EXPECT_EQ(s21_v[i], s21_v[i]);
  }
}

TEST(VECT_test, test9) {
  s21::Vector<float> s21_v = {1, 2, 3, 4};
  s21::Vector<float> s21_v1 = {};
  s21_v1 = s21_v;
  for (size_t i = 0; i < 4; i++) {
    EXPECT_EQ(s21_v1[i], s21_v[i]);
  }
}

TEST(VECT_test, test10) {
  s21::Vector<float> s21_v1 = {1, 2, 3, 4};
  std::vector<float> v1 = {1, 2, 3, 4};
  s21::Vector<float> s21_v2 = {};
  std::vector<float> v2 = {};
  v2.swap(v1);
  s21_v2.swap(s21_v1);
  EXPECT_EQ(s21_v2.size(), v2.size());
  EXPECT_EQ(s21_v2.capacity(), v2.capacity());
}

TEST(VECT_test, test11) {
  s21::Vector<float> s21_v1 = {1, 2, 3, 4};
  std::vector<float> v1 = {1, 2, 3, 4};
  s21_v1.reserve(5);
  v1.reserve(5);
  EXPECT_EQ(s21_v1.size(), v1.size());
  EXPECT_EQ(s21_v1.capacity(), v1.capacity());
  EXPECT_EQ(s21_v1.max_size(), v1.max_size());
}

TEST(VECT_test, test12) {
  s21::Vector<float> s21_v1 = {1, 2, 3, 4};
  std::vector<float> v1 = {1, 2, 3, 4};
  s21_v1.insert(s21_v1.begin() + 1, 5);
  v1.insert(v1.begin() + 1, 5);
  EXPECT_EQ(s21_v1.size(), v1.size());
  EXPECT_EQ(s21_v1.capacity(), v1.capacity());
  for (size_t i = 0; i < 5; i++) {
    EXPECT_EQ(s21_v1[i], v1[i]);
  }
}

TEST(VECT_test, test13) {
  s21::Vector<float> s21_v1 = {1, 2, 3, 4};
  std::vector<float> v1 = {1, 2, 3, 4};
  s21_v1.clear();
  v1.clear();
  EXPECT_EQ(s21_v1.size(), v1.size());
  EXPECT_EQ(s21_v1.capacity(), v1.capacity());
  EXPECT_EQ(s21_v1.max_size(), v1.max_size());
}

TEST(VECT_test, test14) {
  s21::Vector<int> s21_v1 = {1, 2, 3, 4};
  std::vector<int> v1 = {1, 2, 3, 4};
  s21_v1.reserve(5);
  v1.reserve(5);
  s21_v1.shrink_to_fit();
  v1.shrink_to_fit();

  EXPECT_EQ(s21_v1.size(), v1.size());
  EXPECT_EQ(s21_v1.capacity(), v1.capacity());
}

TEST(VECT_test, test15) {
  s21::Vector<int> s21_v1 = {1, 2, 3, 4};
  std::vector<int> v1 = {1, 2, 3, 4};
  s21_v1.clear();
  v1.clear();

  EXPECT_EQ(s21_v1.size(), v1.size());
  EXPECT_EQ(s21_v1.capacity(), v1.capacity());
  EXPECT_EQ(s21_v1.max_size(), v1.max_size());
}

TEST(VECT_test, test16) {
  s21::Vector<int> s21_v1 = {1, 2, 1, 4};

  // тест с утечкой
  // EXPECT_THROW(s21_v1[5], std::out_of_range);

  EXPECT_TRUE(s21_v1[0] == s21_v1[2]);
}

TEST(VECT_test, test17) {
  s21::Vector<int> a = {1, 2, 3};
  s21::Vector<int>::iterator it = a.insert(a.begin() + 1, 10);

  ASSERT_EQ(*it, 10);
}

TEST(VECT_test, test18) {
  s21::Vector<int> a = {1, 2, 3};
  s21::Vector<int>::iterator it1 = a.insert(a.begin() + 1, 10);
  s21::Vector<int>::iterator it2 = a.begin();
  it2++;
  EXPECT_EQ(it1, it2);
}

TEST(VECT_test, test19) {
  s21::Vector<int> a = {1, 2, 3};
  s21::Vector<int>::iterator it1 = a.insert(a.begin() + 1, 10);

  s21::Vector<int>::iterator it2 = a.begin();
  it2++;
  EXPECT_EQ(*it1, *it2);
}
TEST(VECT_test, test20) {
  s21::Vector<int> a = {1, 2, 3};
  s21::Vector<int>::iterator it1 = a.begin();

  s21::Vector<int>::iterator it2 = a.end();
  --it2;
  --it2;
  it2--;
  EXPECT_EQ(*it1, *it2);
}

TEST(VECT_test, test21) {
  s21::Vector<int> a = {1, 2, 3};
  s21::Vector<int>::iterator it1 = a.end();

  s21::Vector<int>::iterator it2 = a.insert(it1, 10);
  it1 = a.end() - 1;
  EXPECT_EQ(it1, it2);
}
TEST(VECT_test, test22) {
  s21::Vector<int> a = {1, 2, 3};
  s21::Vector<int>::iterator it1 = a.end();

  s21::Vector<int>::iterator it2 = a.insert(it1, 10);
  it1 = a.end() - 1;
  EXPECT_TRUE(it1 == it2);
  it1--;
  EXPECT_TRUE(it1 != it2);
}

// ////////////////////
// //      Map       //
// ////////////////////

TEST(map_test, constructorInit) {
  s21::Map<int, int> m1 = {{1, 1}, {1, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {1, 2}, {3, 3}, {4, 4}, {5, 5}};

  auto it1 = m1.begin();

  for (auto it2 = m2.begin(); it2 != m2.end(); it1++, it2++) {
    EXPECT_EQ((*it1).first, (*it2).first);
    EXPECT_EQ((*it1).second, (*it2).second);
  }

  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, constructorEmpty) {
  s21::Map<int, int> m1;
  std::map<int, int> m2;

  EXPECT_EQ(m1.size(), m2.size());

  m1.insert({1, 1});
  m2.insert({1, 1});
  m1.insert({1, 1});
  m2.insert({1, 1});

  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, constructorCopy) {
  s21::Map<int, int> m1({{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}});
  s21::Map<int, int> m2(m1);

  std::map<int, int> m3({{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}});
  std::map<int, int> m4(m3);

  EXPECT_EQ(m1.size(), m3.size());
  EXPECT_EQ(m2.size(), m4.size());

  auto it1 = m1.begin();
  for (auto it2 = m3.begin(); it2 != m3.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);

  auto it3 = m2.begin();
  auto it4 = m4.begin();

  for (; it3 != m2.end(); ++it3, ++it4) EXPECT_EQ(*it3, *it4);
}

TEST(map_test, operatorCopy) {
  s21::Map<int, int> m1 = {{5, 5}, {4, 4}, {1, 1}, {2, 2}, {3, 3}};
  s21::Map<int, int> m2 = m1;

  std::map<int, int> m3 = {{5, 5}, {4, 4}, {1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> m4 = m3;

  EXPECT_EQ(m1.size(), m3.size());
  EXPECT_EQ(m2.size(), m4.size());

  auto it1 = m1.begin();
  for (auto it2 = m3.begin(); it2 != m3.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);

  auto it3 = m2.begin();
  auto it4 = m4.begin();

  for (; it3 != m2.end(); ++it3, ++it4) EXPECT_EQ(*it3, *it4);
}

TEST(map_test, constructorMove) {
  s21::Map<int, int> m1 = {{1, 1}, {1, 2}, {3, 3}, {4, 4}, {5, 5}};
  s21::Map<int, int> m3 = {{1, 1}, {1, 2}, {3, 3}, {4, 4}, {5, 5}};
  s21::Map<int, int> m2(std::move(m1));

  std::map<int, int> m4 = {{1, 1}, {1, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m5 = {{1, 1}, {1, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m6(std::move(m4));

  EXPECT_EQ(m3.size(), m5.size());
  EXPECT_EQ(m2.size(), m6.size());
  EXPECT_EQ(m1.size(), m4.size());

  auto it1 = m2.begin();
  for (auto it2 = m6.begin(); it2 != m6.end(); it1++, it2++) {
    EXPECT_EQ((*it1).second, (*it2).second);
    EXPECT_EQ((*it1).first, (*it2).first);
  }
}

TEST(map_test, operatorMove) {
  s21::Map<int, int> m1 = {{1, 1}, {1, 2}, {3, 3}, {4, 4}, {5, 5}};
  s21::Map<int, int> m3 = {{1, 1}, {1, 2}, {3, 3}, {4, 4}, {5, 5}};
  s21::Map<int, int> m2 = std::move(m1);

  std::map<int, int> m4 = {{1, 1}, {1, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m5 = {{1, 1}, {1, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m6 = std::move(m4);

  EXPECT_EQ(m3.size(), m5.size());
  EXPECT_EQ(m2.size(), m6.size());
  EXPECT_EQ(m1.size(), m4.size());

  auto it1 = m2.begin();
  for (auto it2 = m6.begin(); it2 != m6.end(); it1++, it2++) {
    EXPECT_EQ((*it1).first, (*it2).first);
    EXPECT_EQ((*it1).second, (*it2).second);
  }
}

TEST(map_test, Max_size) {
  s21::Map<int, int> m1 = {{1, 1}, {1, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {1, 2}, {3, 3}, {4, 4}, {5, 5}};
  EXPECT_EQ(m1.max_size(), m2.max_size());
}

TEST(map_test, at1) {
  s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};

  for (size_t i = 1; i < m1.size(); i++) EXPECT_EQ(m1.at(i), m2.at(i));
}

TEST(map_test, begin) {
  s21::Map<int, int> m1 = {{1, 1}};
  std::map<int, int> m2 = {{1, 1}};

  auto it1 = m1.begin();
  auto it2 = m2.begin();

  EXPECT_EQ((*it1).second, (*it2).second);
  EXPECT_EQ((*it1).first, (*it2).first);
}

TEST(map_test, emptyFalse) {
  s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};

  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, emptyTrue) {
  s21::Map<int, int> m1;
  std::map<int, int> m2;

  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, size) {
  s21::Map<int, int> m1;
  std::map<int, int> m2;

  std::pair<int, int> pair = {3, 1};

  m1.insert(pair);
  m2.insert(pair);

  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, size0) {
  s21::Map<int, int> m1;
  std::map<int, int> m2;

  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, clear) {
  s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};

  m1.clear();
  m2.clear();

  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, clearEmpty) {
  s21::Map<int, int> m1;
  std::map<int, int> m2;

  m1.clear();
  m2.clear();

  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, insertPair) {
  s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};

  std::pair<int, int> pair = {6, 6};

  EXPECT_EQ(m1.insert(pair).second, m2.insert(pair).second);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, insertInEmpty) {
  s21::Map<int, int> m1;
  std::map<int, int> m2;

  std::pair<int, int> pair = {3, 1};

  EXPECT_EQ(m1.insert(pair).second, m2.insert(pair).second);

  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, insertNumKey) {
  s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};

  EXPECT_EQ(m1.empty(), m2.empty());

  std::pair<int, int> pair = {3, 1};

  EXPECT_EQ(m1.insert(3, 1).second, m2.insert(pair).second);
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, insert_or_assign) {
  s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {3, 4}, {4, 4}, {5, 5}};

  EXPECT_EQ(m1.empty(), m2.empty());

  m1.insert_or_assign(3, 4);

  EXPECT_EQ(m1.at(3), m2.at(3));
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, insert_or_assign2) {
  s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 4}};

  EXPECT_EQ(m1.empty(), m2.empty());

  m1.insert_or_assign(6, 4);

  EXPECT_EQ(m1.at(6), m2.at(6));
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, swap) {
  s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};

  s21::Map<int, int> m11;
  std::map<int, int> m22;

  m1.swap(m11);
  m2.swap(m22);

  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); it1++, it2++) {
    EXPECT_EQ((*it1).first, (*it2).first);
    EXPECT_EQ((*it1).second, (*it2).second);
  }
}

TEST(map_test, swapEmpty) {
  s21::Map<int, int> m1;
  std::map<int, int> m2;

  s21::Map<int, int> m11;
  std::map<int, int> m22;

  m1.swap(m11);
  m2.swap(m22);

  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());

  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); it1++, it2++) {
    EXPECT_EQ((*it1).first, (*it2).first);
    EXPECT_EQ((*it1).second, (*it2).second);
  }
}

TEST(map_test, containsTrue) {
  s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};

  EXPECT_EQ(m1.contains(1), true);
}

TEST(map_test, containsFalse) {
  s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};

  EXPECT_EQ(m1.contains(0), false);
}

TEST(map_test, Merge2) {
  s21::Map<int, int> s1{{1, 1}, {2, 2}, {3, 3}, {4, 4},
                        {5, 5}, {6, 6}, {7, 7}, {8, 8}};
  s21::Map<int, int> s2{{9, 9}, {-1, -1}, {3, 3}};

  std::map<int, int> s3{{1, 1}, {2, 2}, {3, 3}, {4, 4},
                        {5, 5}, {6, 6}, {7, 7}, {8, 8}};
  std::map<int, int> s4{{9, 9}, {-1, -1}, {3, 3}};

  EXPECT_EQ(s1.size(), s3.size());
  EXPECT_EQ(s2.size(), s4.size());

  s1.merge(s2);
  s3.merge(s4);

  EXPECT_EQ(s1.size(), s3.size());

  auto it1 = s1.begin();
  auto it2 = s3.begin();
  for (; it1 != s1.end(); ++it1, ++it2) {
    EXPECT_EQ((*it1).first, (*it2).first);
    EXPECT_EQ((*it1).second, (*it2).second);
  }
}

TEST(map_test, Erase) {
  s21::Map<int, int> m1;
  std::map<int, int> m2;

  EXPECT_EQ(m1.size(), m2.size());

  m1.insert({1, 1});
  m2.insert({1, 1});

  auto s_pr1 = m1.insert({2, 2});

  m1.erase(s_pr1.first);

  auto it1 = m1.begin();
  auto it2 = m2.begin();
  for (; it1 != m1.end(); ++it1, ++it2) {
    EXPECT_EQ((*it1).first, (*it2).first);
    EXPECT_EQ((*it1).second, (*it2).second);
  }

  EXPECT_EQ(m1.contains(2), false);
}

TEST(map_test, Erase_Test_2) {
  s21::Map<int, int> m1 = {{60, 60}, {58, 58}, {63, 63}, {1, 1},
                           {59, 59}, {61, 61}, {65, 65}};
  std::map<int, int> m2 = {{60, 60}, {58, 58}, {63, 63}, {1, 1},
                           {59, 59}, {61, 61}, {65, 65}};

  auto it1 = m1.begin();
  auto it2 = m2.begin();

  m1.erase(it1);
  m2.erase(it2);

  it1 = m1.begin();
  it2 = m2.begin();

  for (; it1 != m1.end() && it2 != m2.end(); ++it1, ++it2) {
    EXPECT_EQ((*it1).first, (*it2).first);
    EXPECT_EQ((*it1).second, (*it2).second);
  }
}

TEST(map_test, Erase_Test_3) {
  s21::Map<int, int> m1 = {{60, 60}, {58, 58}, {63, 63}, {1, 1},
                           {59, 59}, {61, 61}, {65, 65}};
  std::map<int, int> m2 = {{60, 60}, {58, 58}, {63, 63}, {1, 1},
                           {59, 59}, {61, 61}, {65, 65}};

  auto it1 = m1.begin();
  auto it2 = m2.begin();
  // std::cout << "start " << (*iter1).first << " - " << (*iter2).first <<
  // std::endl;

  m1.insert(62, 62);
  m2.insert({62, 62});

  m1.erase(it1);
  m2.erase(it2);

  it1 = m1.begin();
  it2 = m2.begin();
  for (; it1 != m1.end() && it2 != m2.end(); ++it1, ++it2) {
    EXPECT_EQ((*it1).first, (*it2).first);
    EXPECT_EQ((*it1).second, (*it2).second);
    // std::cout << (*it1).first << " - " << (*it2).first << std::endl;
  }
}

TEST(map_test, Erase_Test_4) {
  s21::Map<int, int> m1 = {{60, 60}, {63, 63}, {1, 1},
                           {61, 61}, {65, 65}, {62, 62}};
  std::map<int, int> m2 = {{60, 60}, {63, 63}, {1, 1},
                           {61, 61}, {65, 65}, {62, 62}};

  auto pair1 = m1.insert(58, 58);
  auto it1 = pair1.first;
  auto it2 = m2.begin();
  m1.erase(it1);
  it1 = m1.begin();
  for (; it1 != m1.end() && it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).first, (*it2).first);
}

TEST(map_test, Erase_Test_5) {
  s21::Map<int, int> m1 = {{10, 10}, {12, 12}};
  std::map<int, int> m2 = {{10, 10}, {12, 12}};

  auto it1 = m1.begin();
  auto it2 = m2.begin();
  m1.erase(it1);
  m2.erase(it2);
  it1 = m1.begin();
  it2 = m2.begin();
  for (; it1 != m1.end() && it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).first, (*it2).first);
}

TEST(map_test, Erase_Test_6) {
  s21::Map<int, int> m1 = {{60, 60}, {55, 55}, {63, 63}, {1, 1},
                           {61, 61}, {65, 65}, {62, 62}};
  std::map<int, int> m2 = {{60, 60}, {55, 55}, {63, 63}, {1, 1},
                           {61, 61}, {65, 65}, {62, 62}};

  auto pair1 = m1.insert(58, 58);
  auto it1 = pair1.first;
  auto it2 = m2.begin();
  m1.erase(it1);
  it1 = m1.begin();
  it2 = m2.begin();
  for (; it1 != m1.end() && it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).first, (*it2).first);
}

TEST(map_test, Erase_Test_7) {
  s21::Map<int, int> m1 = {{4, 4}, {2, 2}, {1, 1}};
  std::map<int, int> m2 = {{4, 4}, {1, 1}};

  auto it1 = m1.begin();
  auto it2 = m2.begin();
  it1++;
  m1.erase(it1);
  it1 = m1.begin();
  it2 = m2.begin();
  for (; it1 != m1.end() && it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).first, (*it2).first);
}

TEST(map_test, Erase_Test_8) {
  s21::Map<int, int> m1 = {{4, 4}, {2, 2}, {1, 1}, {3, 3}, {0, 0}};
  std::map<int, int> m2 = {{4, 4}, {1, 1}, {3, 3}, {0, 0}};

  auto it1 = m1.begin();
  auto it2 = m2.begin();
  EXPECT_EQ(*it1, *it2);
  it1++;
  it1++;
  m1.erase(it1);
  it1 = m1.begin();
  for (; it1 != m1.end() && it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).first, (*it2).first);
}

TEST(map_test, MergeTest_3) {
  s21::Map<int, int> m1 = {{1, 1}};
  s21::Map<int, int> m2 = {{5, 5}, {1, 1}, {7, 7}, {2, 2}, {3, 3}};

  std::map<int, int> m3 = {{1, 1}};
  std::map<int, int> m4 = {{5, 5}, {1, 1}, {7, 7}, {2, 2}, {3, 3}};

  m1.merge(m2);
  m3.merge(m4);
  auto it1 = m1.begin();
  auto it2 = m3.begin();
  for (; it1 != m1.end() && it2 != m3.end(); ++it1, ++it2) {
    EXPECT_EQ((*it1).first, (*it2).first);
    EXPECT_EQ((*it1).second, (*it2).second);
  }
}

TEST(map_test, MergeTest_4) {
  s21::Map<int, int> m1 = {{1, 1}, {0, 0}};
  s21::Map<int, int> m2 = {{5, 5}, {2, 2}, {7, 7}, {0, 0},
                           {3, 3}, {6, 6}, {9, 9}, {10, 10}};
  std::map<int, int> m3 = {{1, 1}, {0, 0}};
  std::map<int, int> m4 = {{5, 5}, {2, 2}, {7, 7}, {0, 0},
                           {3, 3}, {6, 6}, {9, 9}, {10, 10}};

  m1.merge(m2);
  m3.merge(m4);
  auto it1 = m1.begin();
  auto it2 = m3.begin();
  for (; it1 != m1.end() && it2 != m3.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).first, (*it2).first);
}

TEST(map_test, MergeTest_5) {
  s21::Map<int, int> m1 = {{5, 5}, {2, 2}, {6, 6}};
  s21::Map<int, int> m2 = {{5, 5}, {2, 2}, {7, 7}, {0, 0},
                           {3, 3}, {6, 6}, {9, 9}, {10, 10}};
  std::map<int, int> m3 = {{5, 5}, {2, 2}, {6, 6}};
  std::map<int, int> m4 = {{5, 5}, {2, 2}, {7, 7}, {0, 0},
                           {3, 3}, {6, 6}, {9, 9}, {10, 10}};

  m1.merge(m2);
  m3.merge(m4);
  auto it1 = m1.begin();
  auto it2 = m3.begin();
  for (; it1 != m1.end() && it2 != m3.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).first, (*it2).first);
}

TEST(map_test, MergeTest_6) {
  s21::Map<int, int> m1 = {{10, 10}, {13, 13}, {15, 15}};
  s21::Map<int, int> m2 = {{10, 10}, {20, 20}, {15, 15}, {13, 13}, {25, 25}};
  std::map<int, int> m3 = {{10, 10}, {13, 13}, {15, 15}};
  std::map<int, int> m4 = {{10, 10}, {20, 20}, {15, 15}, {13, 13}, {25, 25}};
  m1.merge(m2);
  m3.merge(m4);
  auto it1 = m1.begin();
  auto it2 = m3.begin();
  for (; it1 != m1.end() && it2 != m3.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).first, (*it2).first);
}

TEST(map_test, Emplace_Test) {
  s21::Map<int, int> m1 = {{10, 10}, {13, 13}, {15, 15}};
  std::map<int, int> m2 = {{10, 10}, {13, 13}, {15, 15}};
  m1.insert_many(std::make_pair(5, 5));
  m2.emplace(std::make_pair(5, 5));
  auto it1 = m1.begin();
  auto it2 = m2.begin();
  for (; it1 != m1.end() && it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).first, (*it2).first);
}

TEST(map_test, Emplace) {
  s21::Map<int, int> m1;
  m1.insert_many(std::make_pair(1, 1));
  EXPECT_EQ(m1.contains(1), true);
}

TEST(map_test, EraseOneChild) {
  s21::Map<int, int> m1{{1, 1}, {2, 2}, {3, 3}};
  auto it = m1.begin();
  it++;
  m1.erase(it);
  EXPECT_EQ(m1.contains(2), false);
}

TEST(map_test, EraseOneChild2) {
  s21::Map<int, int> m1{{2, 2}};
  auto it = m1.begin();
  m1.erase(it);
  EXPECT_EQ(m1.contains(2), false);
}

TEST(map_test, EraseTwoChild) {
  s21::Map<int, int> m1{{2, 2}, {1, 1}, {3, 3}};
  auto it = m1.begin();
  it++;
  m1.erase(it);
  EXPECT_EQ(m1.contains(2), false);
}

TEST(map_test, Operator) {
  s21::Map<int, int> m1 = {{1, 1}};
  s21::Map<int, int> m2 = m1;
  auto it1 = m1.begin();
  for (auto it2 = m2.begin(); it2 != m2.end(); it1++, it2++)
    EXPECT_EQ((*it1), (*it2));
}

TEST(map_test, operatorBrace) {
  s21::Map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  EXPECT_EQ(m1[1], 1);
  EXPECT_EQ(m2[1], 1);
  EXPECT_EQ(m1[5], 5);
  EXPECT_EQ(m2[5], 5);
  EXPECT_EQ(m1[1], m2[1]);
  EXPECT_EQ(m1[3], m2[3]);
  EXPECT_EQ(m1[5], m2[5]);
  m1[10] = 10;
  m2[10] = 10;
  m1.at(10) = 5;
  m2.at(10) = 5;
  EXPECT_EQ(m1.at(10), m2.at(10));
  EXPECT_EQ(m1.size(), m2.size());
}

////////////////////
//     Array      //
////////////////////

TEST(ArrayTest, DefaultCinstructor) {
  s21::Array<int, 50> arr1;
  std::array<int, 50> arr2;

  EXPECT_EQ(arr1.size(), arr2.size());
  EXPECT_EQ(arr1.max_size(), arr2.max_size());
}

TEST(ArrayTest, ParamCinstructor) {
  // int
  s21::Array<int, 11> arr1{928, 19, 28, 287, 1872, 9, 0, 18, 100, 6, 9};
  std::array<int, 11> arr2{928, 19, 28, 287, 1872, 9, 0, 18, 100, 6, 9};

  EXPECT_EQ(arr1.size(), arr2.size());
  EXPECT_EQ(arr1.max_size(), arr2.max_size());

  for (int i = 0; i < 11; i++) EXPECT_EQ(arr1.at(i), arr2.at(i));

  // string
  s21::Array<std::string, 5> arr3{"My", "name", "is", "Emil", "."};
  std::array<std::string, 5> arr4{"My", "name", "is", "Emil", "."};

  EXPECT_EQ(arr3.size(), arr4.size());
  EXPECT_EQ(arr3.max_size(), arr4.max_size());

  for (int i = 0; i < 5; i++) EXPECT_EQ(arr3.at(i), arr4.at(i));
}

TEST(ArrayTest, MoveConstructor) {
  // int
  s21::Array<int, 4> arr1 = {-981, 39, -3, 46};
  std::array<int, 4> arr2 = {-981, 39, -3, 46};

  s21::Array<int, 4> arr3 = std::move(arr1);
  std::array<int, 4> arr4 = std::move(arr2);

  auto it1 = arr3.begin();
  for (auto it2 = arr4.begin(); it2 != arr4.end(); ++it1, ++it2) {
    EXPECT_EQ(*it1, *it2);
    // std::cout << *it1 << std::endl;
  }
  EXPECT_EQ(arr1.size(), arr2.size());
  EXPECT_EQ(arr3.size(), arr4.size());

  // string
  s21::Array<std::string, 3> arr5 = {"American", "horror", "story"};
  std::array<std::string, 3> arr6 = {"American", "horror", "story"};

  s21::Array<std::string, 3> arr7 = std::move(arr5);
  std::array<std::string, 3> arr8 = std::move(arr6);

  auto it3 = arr7.begin();
  for (auto it4 = arr8.begin(); it4 != arr8.end(); ++it3, ++it4) {
    EXPECT_EQ(*it3, *it4);
    // std::cout << *it1 << std::endl;
  }
  EXPECT_EQ(arr5.size(), arr6.size());
  EXPECT_EQ(arr7.size(), arr8.size());
}

TEST(ArrayTest, CopyConstructor) {
  s21::Array<int, 4> arr1{-981, 39, -3, 46};
  std::array<int, 4> arr2{-981, 39, -3, 46};

  s21::Array<int, 4> arr3 = arr1;
  std::array<int, 4> arr4 = arr2;

  auto it1 = arr3.begin();
  auto it3 = arr1.begin();
  auto it4 = arr2.begin();
  for (auto it2 = arr4.begin(); it2 != arr4.end(); ++it1, ++it2, ++it3, ++it4) {
    EXPECT_EQ(*it1, *it4);
    EXPECT_EQ(*it1, *it3);
    EXPECT_EQ(*it2, *it3);
    EXPECT_EQ(*it1, *it4);
    EXPECT_EQ(*it1, *it2);
    // std::cout << *it1 << std::endl;
  }
  EXPECT_EQ(arr1.size(), arr2.size());
  EXPECT_EQ(arr3.size(), arr4.size());

  // string
  s21::Array<std::string, 3> arr5{"American", "horror", "story"};
  std::array<std::string, 3> arr6{"American", "horror", "story"};

  s21::Array<std::string, 3> arr7 = arr5;
  std::array<std::string, 3> arr8 = arr6;

  auto it5 = arr5.begin();
  auto it6 = arr6.begin();
  auto it7 = arr7.begin();
  for (auto it8 = arr8.begin(); it8 != arr8.end(); ++it5, ++it6, ++it7, ++it8) {
    EXPECT_EQ(*it7, *it6);
    EXPECT_EQ(*it7, *it5);
    EXPECT_EQ(*it8, *it6);
    EXPECT_EQ(*it8, *it5);
    EXPECT_EQ(*it8, *it7);
    // std::cout << *it7 << std::endl;
  }
  EXPECT_EQ(arr5.size(), arr6.size());
  EXPECT_EQ(arr7.size(), arr8.size());
}

TEST(ArrayTest, Back_and_Front) {
  // int
  s21::Array<int, 9> arr1{10, -9, 72, 91, -2400, -9, -19, 19, -9};
  std::array<int, 9> arr2{10, -9, 72, 91, -2400, -9, -19, 19, -9};

  EXPECT_EQ(arr1.front(), arr2.front());
  EXPECT_EQ(arr1.back(), arr2.back());
  EXPECT_EQ(arr1.size(), arr2.size());

  // string
  s21::Array<std::string, 6> arr3{"check", "back", "and",
                                  "front", "in",   "array"};
  std::array<std::string, 6> arr4{"check", "back", "and",
                                  "front", "in",   "array"};

  EXPECT_EQ(arr3.front(), arr4.front());
  EXPECT_EQ(arr3.back(), arr4.back());
  EXPECT_EQ(arr3.size(), arr4.size());
}

TEST(ArrayTest, Data) {
  // int
  s21::Array<int, 10> arr1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::array<int, 10> arr2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  EXPECT_EQ(*(arr1.data()), *(arr2.data()));
  EXPECT_EQ(arr1.size(), arr2.size());

  // string
  s21::Array<std::string, 6> arr3 = {"check", "back", "and",
                                     "front", "in",   "array"};
  std::array<std::string, 6> arr4 = {"check", "back", "and",
                                     "front", "in",   "array"};

  EXPECT_EQ(*(arr3.data()), *(arr4.data()));
  EXPECT_EQ(arr3.size(), arr4.size());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
