
#include "hk/hook/Trampoline.h"
#include "hk/types.h"
#include "orion/battle.hpp"

HkTrampoline<void, u64, u64, u64> registerAbilityCallbacksHook =
    hk::hook::trampoline(
        [](u64 param_1, u64 param_2, u64 battle_pokemon) -> void {
            u32 fusion_abilities[2];
            u32 battle_pokemon_index = orion::battle::GetBattlePokemonIndex(battle_pokemon);
            u32 primary_ability = orion::battle::GetBattlePokemonField(battle_pokemon, 0x12);
            // Comatose
            if (primary_ability == 213) {
                // As One Ice
                orion::battle::RegisterAbilityCallback(param_1, battle_pokemon_index, 266);
                u8 fusion_ability_count = orion::battle::GetFusionAbilities(param_2, battle_pokemon_index, fusion_abilities);
                (void)fusion_ability_count;
                // Moody
                orion::battle::RegisterAbilityCallback(param_1, battle_pokemon_index, 141);
                // Protean
                orion::battle::RegisterAbilityCallback(param_1, battle_pokemon_index, 168);
                // Tinted Lens
                orion::battle::RegisterAbilityCallback(param_1, battle_pokemon_index, 110);
                // Prism Armor
                orion::battle::RegisterAbilityCallback(param_1, battle_pokemon_index, 232);
                // Dauntless Shield
                orion::battle::RegisterAbilityCallback(param_1, battle_pokemon_index, 235);
            } else {
                orion::battle::RegisterAbilityCallback(param_1, battle_pokemon_index, primary_ability);
                u8 fusion_ability_count = orion::battle::GetFusionAbilities(param_2, battle_pokemon_index, fusion_abilities);
                for (u8 fusion_ability_index = 0; fusion_ability_index < fusion_ability_count; fusion_ability_index++) {
                    orion::battle::RegisterAbilityCallback(param_1, battle_pokemon_index, fusion_abilities[fusion_ability_index]);
                }
            }
        });
extern "C" void hkMain() {
  registerAbilityCallbacksHook.installAtPtr(
      pun<void *>(&orion::battle::RegisterAbilityCallbacks));
}
