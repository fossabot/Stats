#pragma once

#include "ll/api/io/Logger.h"

namespace stats {
namespace hook {
void hook();
void unhook();

ll::io::Logger& getLogger();

namespace player {
void hookPlayerAddEffect();
void hookPlayerBlockUsingShield();
void hookPlayerDropItem();
void hookPlayerStartSleep();
void hookServerPlayerOpenTrading();
void hookPlayerUseItem();
} // namespace player

namespace mob {
void hookMobGetDamageAfterResistanceEffect();
}

namespace block {
void hookBlockInteractedWith();
void hookCakeRemoveSlice();
void hookCampfireBlockUse();
void hookCauldronBlockUseInventory();
void hookCauldronBlockClean();
void hookCraftingTableUse();
void hookFlowerPotBlockPlaceFlower();
void hookNoteBlockAttack();
void hookProjectileHitTargetBlock();
} // namespace block

namespace item {
//void hookFishingRodUsed();
void hookItemStackBaseHurtAndBroken();
}

namespace container {
void hookLevelContainerChanged();
}
} // namespace hook
} // namespace stats