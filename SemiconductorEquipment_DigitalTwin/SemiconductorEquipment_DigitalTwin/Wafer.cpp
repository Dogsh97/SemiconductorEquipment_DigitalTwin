#include "Wafer.h"

Wafer::Wafer(int waferId, int recipeId)
	:Id(waferId),
	RecipeId(recipeId)
{
}

int Wafer::GetWaferId() const {
	return Id;
}

int Wafer::GetRecipeId() const{
	return RecipeId;
}

