/* Copyright (c) 2022-2022 Huawei Technologies Co., Ltd.

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 3, or (at your option) any
   later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING3.  If not see
   <http://www.gnu.org/licenses/>.

   Author: Mingchuan Wu and Yancheng Li
   Create: 2022-08-18
   Description:
    This file contains the declaration of the ToPluginInterface class
*/

#ifndef TO_PLUGIN_INTERFACE_H
#define TO_PLUGIN_INTERFACE_H

#include <vector>
#include "IR/Operation.h"

namespace Plugin_IR {
using std::vector;

/* The ToPluginInterface class defines the plugin interfaces that different
   compilers need to implement. */
class ToPluginInterface {
public:
    /* Operation. */
    virtual vector<Operation> GetAllFunction() = 0;
    /* Decl. */
    virtual Decl GetDeclByID(uintptr_t id) = 0;
    /* Type. */
    virtual Type GetTypeByID(uintptr_t id) = 0;
};
} // namespace Plugin_IR

#endif // TO_PLUGIN_INTERFACE_H