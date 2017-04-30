/*
Copyright Soramitsu Co., Ltd. 2016 All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

                 http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#include "runtime.hpp"
#include "validator.hpp"
#include <ametsuchi/repository.hpp>

#include <infra/ametsuchi/include/ametsuchi/ametsuchi.h>

namespace runtime{

    void processTransaction(const iroha::Transaction& tx){
        if(!validator::account_exist_validator(*tx.creatorPubKey())){
            // Reject
            return;
        }
        if(!validator::permission_validator(*tx.creatorPubKey())){
            // Reject
        }
        if(!validator::logic_validator(tx)){
            // Reject
        }
        repository::append(tx);
    }

};