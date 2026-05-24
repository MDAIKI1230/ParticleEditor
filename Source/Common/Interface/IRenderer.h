#pragma once

class IRenderer
{
public:
	// ---読み込み関数---
	// モデルの読み込み
	virtual int MV1LoadModel(char* _fileName) = 0;
	// 画像の読み込み
	virtual int LoadGraph(char* _fileName) = 0;
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
	virtual void LoadDivGraph(char* _fileName, int _allNum, int _xNum, int _yNum, int _xSize, int _ySize, int* handleBuf) = 0;
	// ---描画関数---
	// モデル描画
	virtual void MV1DrawModel(int _handle) = 0;
	virtual void DrawGraph(int _handle) = 0;
	// ---リソース削除関数---
	// モデル素材削除
	virtual void MV1DeleteModel(int _handle) = 0;
	// 画像素材削除
	virtual void DeleteGraph(int _handle) = 0;
};