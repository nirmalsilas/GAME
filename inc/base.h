#pragma once
#include<map>
#include<string>
#include<vector>

namespace game {

   enum class ErrCode
    {
        ERR_SUCESS = 0,
        CREDENTIAL_CHECK_FAIL,
        FILE_OPEN_FAIL
    };

    static std::map<std::string, int> credentials = { { "nirmal_silas",2151 }, { "riyammdoc",5347},
                                          {"joseph",3498 },{"lilly_mathew",5623 } };

    struct cred
    {
        std::string userName_;
        int pin_ =0;
    };

    #define FILE_PATH "C:\/c++\/GAME_ENGINE_01\/record.xml"
}