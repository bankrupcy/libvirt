/*
 * qemu_snapshot.h: Implementation and handling of snapshots
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "virconftypes.h"
#include "datatypes.h"
#include "qemu_conf.h"
#include "qemu_domainjob.h"

virDomainMomentObj *
qemuSnapObjFromName(virDomainObj *vm,
                    const char *name);

virDomainMomentObj *
qemuSnapObjFromSnapshot(virDomainObj *vm,
                        virDomainSnapshotPtr snapshot);

int
qemuSnapshotFSFreeze(virDomainObj *vm,
                     const char **mountpoints,
                     unsigned int nmountpoints);
int
qemuSnapshotFSThaw(virDomainObj *vm,
                   bool report);

virDomainSnapshotPtr
qemuSnapshotCreateXML(virDomainPtr domain,
                      virDomainObj *vm,
                      const char *xmlDesc,
                      unsigned int flags);

int
qemuSnapshotRevert(virDomainObj *vm,
                   virDomainSnapshotPtr snapshot,
                   unsigned int flags);

int
qemuSnapshotDelete(virDomainObj *vm,
                   virDomainSnapshotPtr snapshot,
                   unsigned int flags);

int
qemuSnapshotCreateDisksTransient(virDomainObj *vm,
                                 qemuDomainAsyncJob asyncJob);
