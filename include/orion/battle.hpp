#pragma once
#include "hk/types.h"

namespace orion::battle {
    void RegisterAbilityCallbacks(u64 param_1, u64 param_2, u64 battle_pokemon);
    void RegisterAbilityCallback(u64 param_1, u64 battle_pokemon, u64 ability);
    u32 GetBattlePokemonIndex(u64 battle_pokemon);
    u32 GetBattlePokemonField(u64 battle_pokemon, u64 field);
    u8 GetFusionAbilities(u64 param_1, u64 battle_pokemon_index, u32* fusion_abilities);
}