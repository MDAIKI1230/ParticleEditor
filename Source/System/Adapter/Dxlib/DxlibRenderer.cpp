#include <DxLib.h>

#include "DxlibRenderer.h"

// モデルの読み込み
int DxlibRenderer::LoadModel(const TCHAR* _fileName)
{
	return DxLib::MV1LoadModel(_fileName);
}

// 画像の読み込み
int DxlibRenderer::LoadGraph(const TCHAR* _fileName)
{
	return DxLib::LoadGraph(_fileName);
}

/// <summary>
/// 画像の分割読み込み
/// </summary>
/// <param name="_fileName">ファイル名</param>
/// <param name="_allNum">分割全体数</param>
/// <param name="_xNum">横の数</param>
/// <param name="_yNum">縦の数</param>
/// <param name="_xSize">分割した一つの横幅</param>
/// <param name="_ySize">分割した一つの縦幅</param>
/// <param name="handleBuf">配列のアドレス</param>
void DxlibRenderer::LoadDivGraph(const TCHAR* _fileName, int _allNum, int _xNum, int _yNum, int _xSize, int _ySize, int* _handleBuf)
{
	DxLib::LoadDivGraph(_fileName, _allNum, _xNum, _yNum, _xSize, _ySize, _handleBuf);
}

// モデル情報セット系
// 行列セット
void DxlibRenderer::ModelSetMatrix(int _handle, Matrix4x4 _mat)
{
	DxLib::MV1SetMatrix(_handle, _mat);
}

// ---描画関数---
// モデル描画
void DxlibRenderer::DrawModel(int _handle)
{
	DxLib::MV1DrawModel(_handle);
}

// 画像描画
void DxlibRenderer::DrawGraph(Vector2* vec, int _handle, bool _transFlag)
{
	DxLib::DrawGraph(vec->x, vec->y, _handle, _transFlag);
}

// ---リソース削除関数---
// モデル素材削除
void DxlibRenderer::DeleteModel(int _handle)
{
	DxLib::DeleteGraph(_handle);
}

// 画像素材削除
void DxlibRenderer::DeleteGraph(int _handle)
{
	DxLib::DeleteGraph(_handle);
}