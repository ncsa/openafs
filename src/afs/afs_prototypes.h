/*
 * Copyright 2000, International Business Machines Corporation and others.
 * All Rights Reserved.
 * 
 * This software has been released under the terms of the IBM Public
 * License.  For details, see the LICENSE file in the top-level source
 * directory or online at http://www.openafs.org/dl/license10.html
 */

#ifndef _AFS_PROTOTYPES_H_
#define _AFS_PROTOTYPES_H_

/* afs_analyze.c */
extern void afs_FinalizeReq(struct vrequest *areq);

extern int afs_Analyze(register struct conn *aconn, afs_int32 acode,
    struct VenusFid *afid, register struct vrequest *areq, int op,
    afs_int32 locktype, struct cell *cellp);
extern int afs_CheckCode(afs_int32 acode, struct vrequest *areq, int where);

/* afs_axscache.c */
extern afs_rwlock_t afs_xaxs;
extern struct axscache *afs_SlowFindAxs(struct axscache **cachep, afs_int32 id);
extern struct axscache *axs_Alloc(void);
extern void afs_RemoveAxs(struct axscache **headp, struct axscache *axsp);
extern void afs_FreeAllAxs(struct axscache **headp);

/* afs_buffer.c */
extern void DInit (int abuffers);
extern char *DRead(register ino_t *fid, register int page);
extern void DRelease (register struct buffer *bp, int flag);
extern int DVOffset (register void *ap);
extern void DZap (ino_t *fid);
extern void DFlush (void);
extern char *DNew (register ino_t *fid, register int page);
extern void shutdown_bufferpackage(void);

/* afs_call.c */
extern int afs_cold_shutdown;
extern afs_int32 afs_setTime;
extern char afs_rootVolumeName[64];
extern void afs_shutdown(void);
extern void afs_FlushCBs(void);
extern struct afs_icl_set *afs_icl_allSets;
extern int afs_icl_CreateLog(char *name, afs_int32 logSize, struct afs_icl_log **outLogpp);
extern int afs_icl_CreateLogWithFlags(char *name, afs_int32 logSize, afs_uint32 flags, 
	struct afs_icl_log **outLogpp);
extern int afs_icl_CopyOut(register struct afs_icl_log *logp, afs_int32 *bufferp, 
        afs_int32 *bufSizep, afs_uint32 *cookiep, afs_int32 *flagsp);
extern int afs_icl_GetLogParms(struct afs_icl_log *logp, afs_int32 *maxSizep, 
        afs_int32 *curSizep);
extern int afs_icl_LogHold(register struct afs_icl_log *logp);
extern int afs_icl_LogHoldNL(register struct afs_icl_log *logp);
extern int afs_icl_LogUse(register struct afs_icl_log *logp);
extern int afs_icl_LogFreeUse(register struct afs_icl_log *logp);
extern int afs_icl_LogSetSize(register struct afs_icl_log *logp, afs_int32 logSize);
extern int afs_icl_ZapLog(register struct afs_icl_log *logp);
extern int afs_icl_LogRele(register struct afs_icl_log *logp);
extern int afs_icl_LogReleNL(register struct afs_icl_log *logp);
extern int afs_icl_ZeroLog(register struct afs_icl_log *logp);
extern int afs_icl_LogFree(register struct afs_icl_log *logp);
extern struct afs_icl_log *afs_icl_FindLog(char *name);
extern int afs_icl_EnumerateLogs(int (*aproc)(), char *arock);
extern int afs_icl_CreateSet(char *name, struct afs_icl_log *baseLogp, 
        struct afs_icl_log *fatalLogp, struct afs_icl_set **outSetpp);
extern int afs_icl_CreateSetWithFlags(char *name, struct afs_icl_log *baseLogp, 
        struct afs_icl_log *fatalLogp, afs_uint32 flags, struct afs_icl_set **outSetpp);
extern int afs_icl_SetEnable(struct afs_icl_set *setp, afs_int32 eventID, int setValue);
extern int afs_icl_GetEnable(struct afs_icl_set *setp, afs_int32 eventID, 
        int *getValuep);
extern int afs_icl_ZeroSet(struct afs_icl_set *setp);
extern int afs_icl_EnumerateSets(int (*aproc)(), char *arock);
extern int afs_icl_AddLogToSet(struct afs_icl_set *setp, struct afs_icl_log *newlogp);
extern int afs_icl_SetSetStat(struct afs_icl_set *setp, int op);
extern int afs_icl_SetHold(register struct afs_icl_set *setp);
extern int afs_icl_ZapSet(register struct afs_icl_set *setp);
extern int afs_icl_SetRele(register struct afs_icl_set *setp);
extern int afs_icl_SetFree(register struct afs_icl_set *setp);
extern struct afs_icl_set *afs_icl_FindSet(char *name);

extern int afs_icl_Event4(register struct afs_icl_set *setp, afs_int32 eventID, 
	afs_int32 lAndT, long p1, long p2, long p3, long p4);
extern int afs_icl_Event3(register struct afs_icl_set *setp, afs_int32 eventID, 
	afs_int32 lAndT, long p1, long p2, long p3);
extern int afs_icl_Event2(register struct afs_icl_set *setp, afs_int32 eventID, 
	afs_int32 lAndT, long p1, long p2);
extern int afs_icl_Event1(register struct afs_icl_set *setp, afs_int32 eventID, 
	afs_int32 lAndT, long p1);
extern int afs_icl_Event0(register struct afs_icl_set *setp, afs_int32 eventID, 
	afs_int32 lAndT);
extern int afs_icl_AppendRecord(register struct afs_icl_log *logp, afs_int32 op, 
	afs_int32 types, long p1, long p2, long p3, long p4);

/* afs_callback.c */
extern afs_int32 afs_allCBs;
extern afs_int32 afs_oddCBs;
extern afs_int32 afs_evenCBs;
extern afs_int32 afs_allZaps;
extern afs_int32 afs_oddZaps;
extern afs_int32 afs_evenZaps;
extern afs_int32 afs_connectBacks;
extern unsigned long lastCallBack_vnode;
extern unsigned int lastCallBack_dv;
extern osi_timeval_t lastCallBack_time;
extern struct interfaceAddr afs_cb_interface;

extern int afs_RXCallBackServer(void);
extern int SRXAFSCB_GetCE(struct rx_call *a_call, afs_int32 a_index, struct AFSDBCacheEntry *a_result);
extern int SRXAFSCB_GetCE64(struct rx_call *a_call, afs_int32 a_index, struct AFSDBCacheEntry64 *a_result);
extern int SRXAFSCB_GetLock (struct rx_call *a_call, afs_int32 a_index, struct AFSDBLock *a_result);
extern int SRXAFSCB_CallBack(struct rx_call *a_call, register struct AFSCBFids *a_fids, struct AFSCBs *a_callbacks);
extern int SRXAFSCB_Probe(struct rx_call *a_call);
extern int SRXAFSCB_InitCallBackState(struct rx_call *a_call);
extern int SRXAFSCB_XStatsVersion(struct rx_call *a_call, afs_int32 *a_versionP);
extern int SRXAFSCB_GetXStats(struct rx_call *a_call, afs_int32 a_clientVersionNum,
        afs_int32 a_collectionNumber, afs_int32 *a_srvVersionNumP,
        afs_int32 *a_timeP, AFSCB_CollData *a_dataP);
extern int afs_RXCallBackServer(void);
extern int shutdown_CB(void) ;
extern int SRXAFSCB_InitCallBackState2(struct rx_call *a_call, struct interfaceAddr *addr);
extern int SRXAFSCB_WhoAreYou(struct rx_call *a_call, struct interfaceAddr *addr);
extern int SRXAFSCB_InitCallBackState3(struct rx_call *a_call, afsUUID *a_uuid);
extern int SRXAFSCB_ProbeUuid(struct rx_call *a_call, afsUUID *a_uuid);
extern int SRXAFSCB_GetServerPrefs(struct rx_call *a_call, afs_int32 a_index,
        afs_int32 *a_srvr_addr, afs_int32 *a_srvr_rank);
extern int SRXAFSCB_GetCellServDB(struct rx_call *a_call, afs_int32 a_index,
    char **a_name, afs_int32 *a_hosts);
extern int SRXAFSCB_GetLocalCell(struct rx_call *a_call, char **a_name);
extern int SRXAFSCB_GetCacheConfig(struct rx_call *a_call, afs_uint32 callerVersion,
        afs_uint32 *serverVersion, afs_uint32 *configCount, cacheConfig *config);
extern int SRXAFSCB_FetchData(struct rx_call *rxcall, struct AFSFid *Fid, afs_int32 Fd,
        afs_int64 Position, afs_int64 Length, afs_int64 *TotalLength);
extern int SRXAFSCB_StoreData(struct rx_call *rxcall, struct AFSFid *Fid, afs_int32 Fd,
        afs_int64 Position, afs_int64 Length, afs_int64 *TotalLength);


/* afs_cbqueue.c */
extern afs_rwlock_t afs_xcbhash;
extern void afs_QueueCallback(struct vcache *avc, unsigned int atime, struct volume *avp);
extern void afs_CheckCallbacks(unsigned int secs);
extern void afs_FlushCBs(void);
extern void afs_FlushServerCBs(struct server *srvp);
extern int afs_BumpBase(void);
extern void afs_InitCBQueue(int doLockInit);
extern void afs_DequeueCallback(struct vcache *avc);

/* afs_cell.c */
extern struct afs_q CellLRU;
extern afs_rwlock_t afs_xcell;
extern afs_int32 afs_cellindex;
extern afs_uint32 afs_nextCellNum;
extern afs_int32 afs_NewCell(char *acellName, register afs_int32 *acellHosts, int aflags, 
        char *linkedcname, u_short fsport, u_short vlport, int timeout, char *aliasFor);
extern struct cell *afs_GetCell(register afs_int32 acell, afs_int32 locktype);
extern struct cell *afs_GetCellByIndex(register afs_int32 cellindex, 
        afs_int32 locktype, afs_int32 refresh);
extern struct cell *afs_GetCellByName2(register char *acellName, afs_int32 locktype, 
        char trydns);
extern struct cell *afs_GetCellByName_Dns(register char *acellName, afs_int32 locktype);
extern struct cell *afs_GetCellByName(register char *acellName, afs_int32 locktype);
extern struct cell *afs_GetCellNoLock(register afs_int32 acell, afs_int32 locktype);

/* afs_chunk.c */
extern afs_int32 afs_FirstCSize;
extern afs_int32 afs_OtherCSize;
extern afs_int32 afs_LogChunk;

/* afs_conn.c */
extern afs_int32 cryptall;
extern afs_rwlock_t afs_xinterface;
extern afs_rwlock_t afs_xconn;
extern struct conn *afs_Conn(register struct VenusFid *afid,
        register struct vrequest *areq, afs_int32 locktype);
extern struct conn *afs_ConnBySA(struct srvAddr *sap, unsigned short aport,
			  afs_int32 acell, struct unixuser *tu,
			  int force_if_down, afs_int32 create, afs_int32 locktype);
extern struct conn *afs_ConnByMHosts(struct server *ahosts[], unsigned short aport,
        afs_int32 acell, register struct vrequest *areq, afs_int32 locktype);
extern struct conn *afs_ConnByHost(struct server *aserver, unsigned short aport, 
        afs_int32 acell, struct vrequest *areq, int aforce, afs_int32 locktype);

/* afs_daemons.c */
extern afs_lock_t afs_xbrs;
extern short afs_brsWaiters;
extern short afs_brsDaemons;
extern struct brequest afs_brs[NBRS];
extern struct afs_osi_WaitHandle AFS_WaitHandler, AFS_CSWaitHandler;
extern afs_int32 afs_gcpags;
extern afs_int32 afs_gcpags_procsize;
extern afs_int32 afs_CheckServerDaemonStarted;
extern afs_int32 PROBE_INTERVAL;

extern void afs_Daemon(void);
extern struct brequest *afs_BQueue(register short aopcode, register struct vcache *avc, 
        afs_int32 dontwait, afs_int32 ause, struct AFS_UCRED *acred, 
        afs_size_t asparm0, afs_size_t asparm1, void *apparm0);

/* afs_dcache.c */
extern u_int afs_min_cache;
extern afs_int32 *afs_dvhashTbl;
extern afs_int32 afs_dhashsize;
extern afs_rwlock_t afs_xdcache;
extern afs_size_t afs_vmMappingEnd;
extern afs_int32 afs_blocksUsed;
extern afs_int32 afs_blocksDiscarded;
extern int afs_WaitForCacheDrain;
extern int cacheDiskType;
extern unsigned char *afs_indexFlags;
extern struct afs_cacheOps *afs_cacheType;
extern ino_t cacheInode;
extern struct osi_file *afs_cacheInodep;
extern void afs_dcacheInit(int afiles, int ablocks, int aDentries, int achunk,
			   int aflags);
extern int afs_PutDCache(register struct dcache *adc);
extern void afs_FlushDCache(register struct dcache *adc);
extern void shutdown_dcache(void);
extern void afs_CacheTruncateDaemon(void);
extern afs_int32 afs_fsfragsize;
extern struct dcache *afs_MemGetDSlot(register afs_int32 aslot, register struct dcache *tmpdc);
extern struct dcache *afs_GetDCache(register struct vcache *avc, afs_size_t abyte, 
        register struct vrequest *areq, afs_size_t *aoffset, afs_size_t *alen, 
        int aflags);
extern struct dcache *afs_FindDCache(register struct vcache *avc, afs_size_t abyte);

/* afs_exporter.c */
extern struct afs_exporter *root_exported;
extern struct afs_exporter *exporter_find(int type);

/* afs_init.c */
extern struct cm_initparams cm_initParams;
extern int afs_resourceinit_flag;
extern afs_rwlock_t afs_puttofileLock;
extern char *afs_sysname;
extern char *afs_sysnamelist[MAXNUMSYSNAMES];
extern int afs_sysnamecount;
extern afs_int32 cacheInfoModTime;

/* afs_lock.c */
extern void Lock_Init(register struct afs_lock *lock);
extern void ObtainLock(register struct afs_lock *lock, int how, 
        unsigned int src_indicator);
extern void ReleaseLock(register struct afs_lock *lock, int how);
extern int Afs_Lock_Trace(int op, struct afs_lock *alock, int type, char *file, int line);
extern void Afs_Lock_Obtain(register struct afs_lock *lock, int how);
extern void Afs_Lock_ReleaseR(register struct afs_lock *lock);
extern void Afs_Lock_ReleaseW(register struct afs_lock *lock);
extern void afs_osi_SleepR(register char *addr, register struct afs_lock *alock);
extern void afs_osi_SleepW(register char *addr, register struct afs_lock *alock);
extern void afs_osi_SleepS(register char *addr, register struct afs_lock *alock);
#ifndef AFS_NOBOZO_LOCK
extern void afs_BozonLock(struct afs_bozoLock *alock, struct vcache *avc);
extern void afs_BozonUnlock(struct afs_bozoLock *alock, struct vcache *avc);
extern void afs_BozonInit(struct afs_bozoLock *alock, struct vcache *avc);
extern int afs_CheckBozonLock(struct afs_bozoLock *alock);
extern int afs_CheckBozonLockBlocking(struct afs_bozoLock *alock);
#endif




/* afs_mariner.c */
extern afs_int32 afs_mariner;
extern afs_int32 afs_marinerHost;
extern struct rx_service *afs_server;

/* afs_memcache.c */
extern void *afs_MemCacheOpen(ino_t blkno);
extern int afs_InitMemCache(int size, int blkSize, int flags);
extern int afs_MemCacheClose(char *file);
extern void *afs_MemCacheOpen(ino_t blkno);
extern int afs_MemReadBlk(register struct memCacheEntry *mceP, int offset, char *dest, int size);
extern int afs_MemReadvBlk(register struct memCacheEntry *mceP, int offset, struct iovec *iov, int nio, int size);
extern int afs_MemReadUIO(ino_t blkno, struct uio *uioP);
extern int afs_MemWriteBlk(register struct memCacheEntry *mceP, int offset, char *src, int size);
extern int afs_MemWritevBlk(register struct memCacheEntry *mceP, int offset, struct iovec *iov, int nio, int size);
extern int afs_MemWriteUIO(ino_t blkno, struct uio *uioP);
extern int afs_MemCacheTruncate(register struct memCacheEntry *mceP, int size);
extern int afs_MemCacheStoreProc(register struct rx_call *acall, register struct memCacheEntry *mceP, 
        register afs_int32 alen, struct vcache *avc, int *shouldWake, afs_size_t *abytesToXferP, 
        afs_size_t *abytesXferredP, afs_int32 length);
extern int afs_MemCacheFetchProc(register struct rx_call *acall, register struct memCacheEntry *mceP, 
        afs_size_t abase, struct dcache *adc, struct vcache *avc, afs_size_t *abytesToXferP, 
        afs_size_t *abytesXferredP, afs_int32 lengthFound);
extern void shutdown_memcache(void);


/* afs_nfsclnt.c */
extern struct afs_exporter *afs_nfsexported;
extern struct afs_exporter *afs_nfsexporter;

/* afs_osi.c */
extern void afs_osi_Invisible(void);
extern void afs_osi_RxkRegister(void);
extern void afs_osi_MaskSignals(void);
extern void afs_osi_UnmaskRxkSignals(void);
#if AFS_GCPAGS
extern const struct AFS_UCRED *afs_osi_proc2cred(AFS_PROC *pr);
extern void afs_osi_TraverseProcTable(void);
#endif /* AFS_GCPAGS */
extern void *afs_osi_Alloc(size_t x);
extern void *afs_osi_Alloc_NoSleep(size_t x);

/* afs_osi_pag.c */
extern afs_uint32 genpag(void);
extern afs_uint32 getpag(void);
extern int afs_InitReq(register struct vrequest *av, struct AFS_UCRED *acred);
extern afs_uint32 afs_get_pag_from_groups(gid_t g0a, gid_t g1a);
extern void afs_get_groups_from_pag(afs_uint32 pag, gid_t *g0p, gid_t *g1p);
extern afs_int32 PagInCred(const struct AFS_UCRED *cred);

/* afs_osi.c */
extern afs_lock_t afs_ftf;
extern void afs_osi_Free(void *x, size_t asize);

/* afs_osi_alloc.c */
extern afs_int32 afs_preallocs;
extern afs_lock_t osi_fsplock;
extern afs_lock_t osi_flplock;
extern void *osi_AllocLargeSpace(size_t size);
extern void *osi_AllocMediumSpace(size_t size);
extern void *osi_AllocSmallSpace(size_t size);
#if 0 /* defines are rewriting this */
extern char *osi_AllocSmall(register afs_int32 size, register afs_int32 morespace);
#endif
extern void osi_FreeLargeSpace(void *adata);
extern void osi_FreeMediumSpace(void *adata);
extern void osi_FreeSmallSpace(void *adata);

/* ARCH/osi_misc.c */
extern void osi_iput(struct inode *ip);

/* ARCH/osi_sleep.c */
extern void afs_osi_InitWaitHandle(struct afs_osi_WaitHandle *achandle);
extern void afs_osi_CancelWait(struct afs_osi_WaitHandle *achandle);
extern int afs_osi_Wait(afs_int32 ams, struct afs_osi_WaitHandle *ahandle, int aintok);
#ifndef afs_osi_Wakeup
extern void afs_osi_Wakeup(int *event);
#endif
#ifndef afs_osi_Sleep
extern void afs_osi_Sleep(int *event);
#endif

/* ARCH/osi_file.c */
extern int afs_osicred_initialized;

/* ARCH/osi_vnodeops.c */
extern struct vnodeops Afs_vnodeops;

/* afs_osifile.c */
#ifdef AFS_SGI62_ENV
extern void *osi_UFSOpen(ino_t);
#else
extern void *osi_UFSOpen();
#endif

/* afs_osi_pag.c */
extern afs_uint32 pag_epoch;
extern afs_uint32 pagCounter;

/* OS/osi_vfsops.c */
extern struct vfs *afs_globalVFS;
extern struct vcache *afs_globalVp;
extern void vcache2inode(struct vcache *avc);

/* afs_pioctl.c */
extern struct VenusFid afs_rootFid;
extern afs_int32 afs_waitForever;
extern short afs_waitForeverCount;
extern afs_int32 afs_showflags;
extern int afs_defaultAsynchrony;

/* afs_server.c */
extern afs_rwlock_t afs_xsrvAddr;
extern afs_rwlock_t afs_xserver;
extern struct srvAddr *afs_srvAddrs[NSERVERS];
extern struct server *afs_servers[NSERVERS];
extern int afs_totalServers;
extern struct server *afs_setTimeHost;
extern struct server *afs_FindServer (afs_int32 aserver, ushort aport,
				     afsUUID *uuidp, afs_int32 locktype);
extern struct server *afs_GetServer(afs_uint32 *aserver, afs_int32 nservers,
				    afs_int32 acell, u_short aport,
				    afs_int32 locktype, afsUUID *uuidp,
				    afs_int32 addr_uniquifier);
extern void afs_MarkServerUpOrDown(struct srvAddr *sa, int a_isDown);
extern void afs_ServerDown(struct srvAddr *sa);

/* afs_osidnlc.c */
extern int osi_dnlc_enter(struct vcache *adp, char *aname, struct vcache *avc, afs_hyper_t *avno);
extern struct vcache *osi_dnlc_lookup(struct vcache *adp, char *aname, int locktype);
extern int osi_dnlc_remove(struct vcache *adp, char *aname, struct vcache *avc );
extern int osi_dnlc_purgedp(struct vcache *adp);
extern int osi_dnlc_purgevp(struct vcache *avc);
extern int osi_dnlc_purge(void);
extern int osi_dnlc_purgevol(struct VenusFid *fidp);
extern int osi_dnlc_init(void);
extern int osi_dnlc_shutdown(void);


/* UKERNEL/afs_usrops.c */
extern void uafs_Shutdown(void);

/* afs_user.c */
extern afs_rwlock_t afs_xuser;
extern struct unixuser *afs_users[NUSERS];
extern struct unixuser *afs_FindUser(afs_int32 auid, afs_int32 acell, afs_int32 locktype);
extern struct unixuser *afs_GetUser(register afs_int32 auid, 
        afs_int32 acell, afs_int32 locktype);
#if AFS_GCPAGS
extern afs_int32 afs_GCPAGs(afs_int32 *ReleasedCount);
extern void afs_GCPAGs_perproc_func(AFS_PROC *pproc);
#endif /* AFS_GCPAGS */
extern void afs_ComputePAGStats(void);
extern void afs_PutUser(register struct unixuser *au, afs_int32 locktype);

/* afs_util.c */
extern char *afs_cv2string(char *ttp, afs_uint32 aval);
extern void print_internet_address(char *preamble, struct srvAddr *sa,
			    char *postamble, int flag);
extern afs_int32 afs_data_pointer_to_int32(const void *p);

#if 0 /* problems - need to change to varargs, right now is incorrect usage
	throughout code */
extern void afs_warn(char *a, long b, long c, long d, long e, long f, long g, 
        long h, long i, long j);
extern void afs_warnuser(char *a, long b, long c, long d, long e, long f,
	long g, long h, long i, long j);
#endif
extern void afs_CheckLocks(void);



/* afs_vcache.c */
extern afs_int32 afs_maxvcount;
extern afs_int32 afs_vcount;
extern int afsvnumbers;
extern afs_rwlock_t afs_xvcache;
extern afs_lock_t afs_xvcb;
extern struct vcache *freeVCList;
extern struct vcache *Initial_freeVCList;
extern struct afs_q VLRU;
extern afs_int32 vcachegen;
extern unsigned int afs_paniconwarn;
extern struct vcache *afs_vhashT[VCSIZE];
extern afs_int32 afs_bulkStatsLost;
extern int afs_norefpanic;

void afs_vcacheInit(int astatSize);
extern struct vcache *afs_FindVCache(struct VenusFid *afid, afs_int32 lockit,
				     afs_int32 locktype, afs_int32 *retry, afs_int32 flag);
extern afs_int32 afs_FetchStatus(struct vcache *avc, struct VenusFid *afid,
			     struct vrequest *areq,
			     struct AFSFetchStatus *Outsp);

extern afs_int32 afs_FlushVCBs(afs_int32 lockit);
extern void afs_InactiveVCache(struct vcache *avc, struct AFS_UCRED *acred);
extern struct vcache *afs_LookupVCache(struct VenusFid *afid,
				       struct vrequest *areq,
				       afs_int32 *cached, afs_int32 locktype,
				       struct vcache *adp, char *aname);
extern int afs_FlushVCache(struct vcache *avc, int *slept);
extern struct vcache *afs_GetRootVCache(struct VenusFid *afid,
					struct vrequest *areq, afs_int32 *cached,
					struct volume *tvolp, afs_int32 locktype);
extern struct vcache *afs_NewVCache(struct VenusFid *afid,
				    struct server *serverp,
				    afs_int32 lockit, afs_int32 locktype);
extern int afs_VerifyVCache2(struct vcache *avc, struct vrequest *areq);
extern struct vcache *afs_GetVCache(register struct VenusFid *afid, struct vrequest *areq, 
        afs_int32 *cached, struct vcache *avc, afs_int32 locktype);
extern void afs_PutVCache(register struct vcache *avc, afs_int32 locktype);
extern void afs_ProcessFS(register struct vcache *avc, register struct AFSFetchStatus *astat, 
        struct vrequest *areq);

/* VNOPS/afs_vnop_access.c */
extern afs_int32 afs_GetAccessBits(register struct vcache *avc, register afs_int32 arights, 
        register struct vrequest *areq);
extern int afs_AccessOK(struct vcache *avc, afs_int32 arights, struct vrequest *areq, 
        afs_int32 check_mode_bits);
#if defined(AFS_SUN5_ENV) || (defined(AFS_SGI_ENV) && !defined(AFS_SGI65_ENV))
extern int afs_access(OSI_VC_DECL(avc), register afs_int32 amode, int flags, struct AFS_UCRED *acred);
#else
extern int afs_access(OSI_VC_DECL(avc), register afs_int32 amode, struct AFS_UCRED *acred);
#endif
extern int afs_getRights(OSI_VC_DECL(avc), register afs_int32 arights, struct AFS_UCRED *acred);

/* VNOPS/afs_vnop_attrs.c */
extern int afs_CopyOutAttrs(register struct vcache *avc, register struct vattr *attrs);
#if     defined(AFS_SUN5_ENV) || defined(AFS_SGI_ENV)
extern int afs_getattr(OSI_VC_DECL(avc), struct vattr *attrs, int flags, struct AFS_UCRED *acred);
#else
extern int afs_getattr(OSI_VC_DECL(avc), struct vattr *attrs, struct AFS_UCRED *acred);
#endif
extern int afs_VAttrToAS(register struct vcache *avc, register struct vattr *av, 
        register struct AFSStoreStatus *as);
#if defined(AFS_SUN5_ENV) || defined(AFS_SGI_ENV)
extern int afs_setattr(OSI_VC_DECL(avc), register struct vattr *attrs, int flags, struct AFS_UCRED *acred);
#else
extern int afs_setattr(OSI_VC_DECL(avc), register struct vattr *attrs, struct AFS_UCRED *acred);
#endif

/* VNOPS/afs_vnop_create.c */
#ifdef  AFS_OSF_ENV
extern int afs_create(struct nameidata *ndp, struct vattr *attrs);
#else   /* AFS_OSF_ENV */
#ifdef AFS_SGI64_ENV
extern int afs_create(OSI_VC_DECL(adp), char *aname, struct vattr *attrs, int flags, 
        int amode, struct vcache **avcp, struct AFS_UCRED *acred);
#else /* AFS_SGI64_ENV */
extern int afs_create(OSI_VC_DECL(adp), char *aname, struct vattr *attrs, enum vcexcl aexcl,
        int amode, struct vcache **avcp, struct AFS_UCRED *acred);
#endif /* AFS_SGI64_ENV */
#endif /* AFS_OSF_ENV */
extern int afs_LocalHero(register struct vcache *avc, register struct dcache *adc, 
        register AFSFetchStatus *astat, register int aincr);


/* VNOPS/afs_vnop_lookup.c */
extern char *afs_strcat(register char *s1, register char *s2);
extern char *afs_index(register char *a, register char c);
extern int EvalMountPoint(register struct vcache *avc, struct vcache *advc,
        struct volume **avolpp, register struct vrequest *areq);
extern void afs_InitFakeStat(struct afs_fakestat_state *state);
extern int afs_EvalFakeStat(struct vcache **avcp, struct afs_fakestat_state *state, 
        struct vrequest *areq);
extern int afs_TryEvalFakeStat(struct vcache **avcp, struct afs_fakestat_state *state, 
        struct vrequest *areq);
extern void afs_PutFakeStat(struct afs_fakestat_state *state);
extern int afs_ENameOK(register char *aname);



/* VNOPS/afs_vnop_read.c */
extern afs_int32 maxIHint;
extern afs_int32 nihints;
extern afs_int32 usedihint;
extern int afs_MemRead(register struct vcache *avc, struct uio *auio, struct AFS_UCRED *acred, 
        daddr_t albn, struct buf **abpp, int noLock);


/* VNOPS/afs_vnop_readdir.c */
extern int afs_rd_stash_i;

/* VNOPS/afs_vnop_symlink.c */
extern int afs_MemHandleLink(register struct vcache *avc, struct vrequest *areq);

/* VNOPS/afs_vnop_flock.c */
extern afs_int32 lastWarnTime;

/* VNOPS/afs_vnop_write.c */
extern int afs_MemWrite(register struct vcache *avc, struct uio *auio, int aio, 
	struct AFS_UCRED *acred, int noLock);


/* afs_volume.c */
extern afs_int32 afs_FVIndex;
extern afs_int32 afs_volCounter;
extern afs_rwlock_t afs_xvolume;
extern struct volume *afs_volumes[NVOLS];
extern ino_t volumeInode;
extern struct volume *afs_FindVolume(struct VenusFid *afid, afs_int32 locktype);
extern struct volume *afs_freeVolList;
extern afs_int32 fvTable[NFENTRIES];
extern void InstallVolumeEntry(struct volume *av, struct vldbentry *ve,
			       int acell);
extern void InstallNVolumeEntry(struct volume *av, struct nvldbentry *ve,
			 int acell);
extern void InstallUVolumeEntry(struct volume *av, struct uvldbentry *ve,
			 int acell, struct cell *tcell, struct vrequest *areq);
extern void afs_ResetVolumeInfo(struct volume *tv);
extern struct volume *afs_MemGetVolSlot(void);
extern void afs_ResetVolumes(struct server *srvp);
extern struct volume *afs_GetVolume(struct VenusFid *afid, struct vrequest *areq, 
        afs_int32 locktype);
extern struct volume *afs_GetVolumeByName(register char *aname, afs_int32 acell, 
        int agood, struct vrequest *areq, afs_int32 locktype);






/* MISC PROTOTYPES - THESE SHOULD NOT BE HERE */
/* MOVE THEM TO APPROPRIATE LOCATIONS */
extern struct rx_securityClass *rxnull_NewClientSecurityObject(void);
extern struct rx_securityClass *rxnull_NewServerSecurityObject(void);

extern int RXAFSCB_ExecuteRequest();
extern int RXSTATS_ExecuteRequest();



#if defined(AFS_SUN5_ENV) || defined(AFS_LINUX20_ENV) || defined(AFS_AIX_ENV) || defined(AFS_DARWIN_ENV) || defined(AFS_FBSD_ENV)
#include "../afs/osi_prototypes.h"
#endif

#endif /* _AFS_PROTOTYPES_H_ */

