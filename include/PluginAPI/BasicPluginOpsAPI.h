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
    This file contains the declaration of the BasicPluginAPI class.
*/

#ifndef BASIC_PLUGIN_OPS_API_H
#define BASIC_PLUGIN_OPS_API_H

#include "Dialect/PluginOps.h"

#include <vector>
#include <string>

namespace PluginAPI {
using std::vector;
using std::string;
using namespace mlir::Plugin;

/* The BasicPluginAPI class defines the basic plugin API, both the plugin
   client and the server should inherit this class and implement there own
   defined API. */
class BasicPluginOpsAPI {
public:
    BasicPluginOpsAPI() = default;
    virtual ~BasicPluginOpsAPI() = default;

    virtual uint64_t CreateBlock(uint64_t, uint64_t) = 0;
    virtual void DeleteBlock(uint64_t, uint64_t) = 0;
    virtual void SetImmediateDominator(uint64_t, uint64_t, uint64_t) = 0;
    virtual uint64_t GetImmediateDominator(uint64_t, uint64_t) = 0;
    virtual uint64_t RecomputeDominator(uint64_t, uint64_t) = 0;
    virtual vector<FunctionOp> GetAllFunc() = 0;
    virtual vector<LocalDeclOp> GetDecls(uint64_t funcID) = 0;
    virtual vector<LoopOp> GetLoopsFromFunc(uint64_t) = 0;
    virtual LoopOp GetLoopById(uint64_t) = 0;
    virtual bool IsBlockInside(uint64_t, uint64_t) = 0;
    virtual vector<uint64_t> GetBlocksInLoop(uint64_t) = 0;
    virtual void AddLoop(uint64_t, uint64_t, uint64_t) = 0;
    virtual uint64_t AllocateNewLoop(void) = 0;
    virtual void DeleteLoop(uint64_t) = 0;
    virtual uint64_t GetHeader(uint64_t) = 0;
    virtual uint64_t GetLatch(uint64_t) = 0;
    virtual vector<std::pair<uint64_t, uint64_t> > GetLoopExits(uint64_t) = 0;
    virtual std::pair<uint64_t, uint64_t> GetLoopSingleExit(uint64_t) = 0;
    virtual LoopOp GetBlockLoopFather(uint64_t) = 0;
    virtual PhiOp GetPhiOp(uint64_t) = 0;
    virtual CallOp GetCallOp(uint64_t) = 0;
    virtual bool SetLhsInCallOp(uint64_t, uint64_t) = 0;
    virtual uint64_t CreateCallOp(uint64_t, uint64_t, vector<uint64_t> &) = 0;
    virtual uint64_t CreateCondOp(uint64_t, IComparisonCode, uint64_t, uint64_t) = 0;
    virtual mlir::Value GetResultFromPhi(uint64_t) = 0;

    virtual uint64_t CreateAssignOp(uint64_t, IExprCode, vector<uint64_t> &) = 0;
    virtual bool AddArgInPhiOp(uint64_t, uint64_t, uint64_t, uint64_t) = 0;
    virtual PhiOp CreatePhiOp(uint64_t, uint64_t) = 0;
    virtual bool UpdateSSA() = 0;
    virtual vector<PhiOp> GetPhiOpsInsideBlock(uint64_t bb) = 0;
    virtual bool IsDomInfoAvailable() = 0;
}; // class BasicPluginOpsAPI
} // namespace PluginAPI

#endif // BASIC_PLUGIN_OPS_API_H