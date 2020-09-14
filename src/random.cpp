/*
 core/random.hpp - insilico's own RNG (random number generator) header and source

 Copyright (C) 2015 Pranav Kulkarni, Collins Assisi Lab, IISER, Pune <pranavcode@gmail.com>

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <random>

#include "include/random.hpp"

using namespace std;

template <class T> 
T newinsilico::random::rand(T min, T max) {
    random_device rd;
    mt19937_64 gen(rd());
    uniform_real_distribution<> dist(min, max+1);
    return dist(gen);
  } // function rand

template<class T>
T newinsilico::random::rand(T max) {
  return rand(0, max);
} // function rand
