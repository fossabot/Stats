#include "mod/Stats/Command/RegisterCommand.h"

#include <string>

#include "ll/api/Expected.h"
#include "ll/api/command/CommandHandle.h"
#include "ll/api/command/CommandRegistrar.h"
#include "ll/api/i18n/I18n.h"
#include "mc/server/commands/CommandOrigin.h"
#include "mc/server/commands/CommandOutput.h"
#include "mc/server/commands/CommandPermissionLevel.h"
#include "mc/world/actor/Actor.h"
#include "mc/world/actor/player/Player.h"


#include "mod/Stats/Form/Form.h"
#include "mod/Stats/StatsType.h"


enum StatsType : int { custom = 1, mined, broken, crafted, used, picked_up, dropped, killed, killed_by };

using namespace ll::i18n_literals;

namespace stats::command {
struct StatsGui {
    StatsType statsType;
};

void registerCommand() {
    auto& cmd = ll::command::CommandRegistrar::getInstance()
                    .getOrCreateCommand("stats", "LK-Stats - " + "command.desc"_tr(), CommandPermissionLevel::Any);
    cmd.overload<StatsGui>()
        .text("gui")
        .optional("statsType")
        .execute([&](CommandOrigin const& origin, CommandOutput& output, StatsGui const& param) {
            auto* entity = origin.getEntity();
            if (entity == nullptr || !entity->hasType(::ActorType::Player)) {
                output.error("command.error.notplayer"_tr());
            }
            Player* player = (Player*)entity;
            // lk::MyMod::getInstance().getSelf().getLogger().info("cmd {} {}", player->getRealName(), param.statsType);
            switch (param.statsType) {
            case StatsType::custom:
                form::sendStatsGui(*player, StatsDataType::custom);
                break;
            case StatsType::mined:
                form::sendStatsGui(*player, StatsDataType::mined);
                break;
            case StatsType::broken:
                form::sendStatsGui(*player, StatsDataType::broken);
                break;
            case StatsType::crafted:
                form::sendStatsGui(*player, StatsDataType::crafted);
                break;
            case StatsType::used:
                form::sendStatsGui(*player, StatsDataType::used);
                break;
            case StatsType::picked_up:
                form::sendStatsGui(*player, StatsDataType::picked_up);
                break;
            case StatsType::dropped:
                form::sendStatsGui(*player, StatsDataType::dropped);
                break;
            case StatsType::killed:
                form::sendStatsGui(*player, StatsDataType::killed);
                break;
            case StatsType::killed_by:
                form::sendStatsGui(*player, StatsDataType::killed_by);
                break;
            default:
                form::sendMainGui(*player);
                break;
            }
        });
}
} // namespace stats::command