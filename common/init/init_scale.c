/*
   Copyright (c) 2014, The Linux Foundation. All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_msm.h"

void init_msm_properties(unsigned long msm_id, unsigned long msm_ver, char *board_type)
{
    char platform[PROP_VALUE_MAX];
    char model[110];
    FILE* fp;
    int rc;

    UNUSED(msm_id);
    UNUSED(msm_ver);
    UNUSED(board_type);

    rc = property_get("ro.board.platform", platform);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    fp = fopen("/proc/app_info", "rb");
    while (fgets(model, 100, fp))
        if (strstr(model, "board_id") != NULL)
            break;

    /* L01 version b */
    if (strstr(model, "MSM8909_SCL_L01_VB") != NULL) {
	property_set("ro.product.model", "msm8909");
        property_set("ro.product.name", "y6");
        property_set("ro.product.device", "y6");
        property_set("ro.build.product", "y6");
        property_set("ro.build.description", "SCL-L01-user 5.1.1 GRJ90 C432B150 release-keys");
        property_set("ro.build.fingerprint", "Huawei/SCL-L01/hwSCL-Q:5.1.1/HuaweiSCL-L01/C432B150:user/release-keys");
    }

	/* L02 version b */
    if (strstr(model, "MSM8909_SCL_L02_VB") != NULL) {
	property_set("ro.product.model", "msm8909");
        property_set("ro.product.name", "y6");
        property_set("ro.product.device", "y6");
        property_set("ro.build.product", "y6");
        property_set("ro.build.description", "SCL-L02-user 5.1.1 GRJ90 C432B150 release-keys");
        property_set("ro.build.fingerprint", "Huawei/SCL-L02/hwSCL-Q:5.1.1/HuaweiSCL-L02/C432B150:user/release-keys");
    }

	/* L03 version b */
    if (strstr(model, "MSM8909_SCL_L03_VB") != NULL) {
	property_set("ro.product.model", "msm8909");
        property_set("ro.product.name", "y6");
        property_set("ro.product.device", "y6");
        property_set("ro.build.product", "y6");
        property_set("ro.build.description", "SCL-L03-user 5.1.1 GRJ90 C432B150 release-keys");
        property_set("ro.build.fingerprint", "Huawei/SCL-L03/hwSCL-Q:5.1.1/HuaweiSCL-L03/C432B150:user/release-keys");
    }

	/* L21 version b */
    if (strstr(model, "MSM8909_SCL_L21_VB") != NULL) {
	property_set("ro.product.model", "msm8909");
        property_set("ro.product.name", "y6");
        property_set("ro.product.device", "y6");
        property_set("ro.build.product", "y6");
	property_set("ro.config.dsds_mode", "umts_gsm");
        property_set("persist.dsds.enabled", "true");
        property_set("persist.radio.multisim.config", "dsds");
	property_set("ro.multi.rid", "true");
        property_set("ro.config.hw_showSimName", "true");
        property_set("ro.dual.sim.phone", "true");
        property_set("ro.build.description", "SCL-L21-user 5.1.1 GRJ90 C432B150 release-keys");
        property_set("ro.build.fingerprint", "Huawei/SCL-L21/hwSCL-Q:5.1.1/HuaweiSCL-L21/C432B150:user/release-keys");
    }

	/* Y538 version b */
    if (strstr(model, "MSM8909_Y538_A1_VB") != NULL) {
	property_set("ro.product.model", "msm8909");
        property_set("ro.product.name", "Y538");
        property_set("ro.product.device", "hwY538");
        property_set("ro.build.product", "Y538");
        property_set("ro.build.description", "Y538-user 5.1.1 GRJ90 C237B150 release-keys");
        property_set("ro.build.fingerprint", "Huawei/Y538/hwY538:5.1.1/HuaweiY538/C237B150:user/release-keys");
    }

}
