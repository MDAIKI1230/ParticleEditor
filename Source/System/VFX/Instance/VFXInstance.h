#pragma once

#include "Emitter/Emitter.h"
#include "Module/Module.h"

class VFXInstance
{
public:
	// エミッター取得
	std::vector<Emitter>& GetEmitters() { return emitters; }
	// モジュール取得
	std::vector<Module*>& GetModules() { return modules; }
private:
	// エミッタ―リスト
	std::vector<Emitter> emitters;
	// 使うモジュール群
	std::vector<Module*> modules;
};