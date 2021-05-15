//
// This file is a part of UERANSIM open source project.
// Copyright (c) 2021 ALİ GÜNGÖR.
//
// The software and all associated files are licensed under GPL-3.0
// and subject to the terms and conditions defined in LICENSE file.
//

#include "task.hpp"

#include <lib/asn/utils.hpp>
#include <lib/rrc/encode.hpp>
#include <ue/nas/task.hpp>
#include <ue/nts.hpp>
#include <utils/common.hpp>

#include <asn/rrc/ASN_RRC_MIB.h>

namespace nr::ue
{

void UeRrcTask::receiveMib(int cellId, const ASN_RRC_MIB &msg)
{
    auto &desc = m_cellDesc[cellId];

    desc.isBarred = msg.cellBarred == ASN_RRC_MIB__cellBarred_barred;
    desc.isIntraFreqReselectAllowed = msg.intraFreqReselection == ASN_RRC_MIB__intraFreqReselection_allowed;
}

} // namespace nr::ue