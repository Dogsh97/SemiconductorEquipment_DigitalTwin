#pragma once

class Wafer{
	private:
		int Id;
		int RecipeId;
	public:
		Wafer(int waferId, int recipeId);
		int GetWaferId() const;
		int GetRecipeId() const;
};