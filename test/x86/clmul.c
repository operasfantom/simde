/* Copyright (c) 2020 Evan Nemerson <evan@nemerson.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#define SIMDE_TESTS_CURRENT_ISAX clmul
#include <simde/x86/clmul.h>
#include <test/x86/avx512/test-avx512.h>

static int
test_simde_x_clmul_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a;
    const uint64_t b;
    const uint64_t r;
  } test_vec[] = {
    { UINT64_C( 3172393302982392208),
      UINT64_C(13735374816641287390),
      UINT64_C( 3846784924301700320) },
    { UINT64_C( 2044753197648351232),
      UINT64_C(17171186745849913133),
      UINT64_C( 9324690142177808384) },
    { UINT64_C(15878177146981999432),
      UINT64_C(17725848129279761057),
      UINT64_C(14704261962833067592) },
    { UINT64_C(14248111140186106732),
      UINT64_C(11051947085071581716),
      UINT64_C( 2350367993186272112) },
    { UINT64_C( 3864970927616292810),
      UINT64_C( 3037243358930395708),
      UINT64_C( 4601354589070078104) },
    { UINT64_C(14194084542956518303),
      UINT64_C( 5148061316303689350),
      UINT64_C(18148658662839280834) },
    { UINT64_C(10905099652190648717),
      UINT64_C(16104009427115953300),
      UINT64_C( 6274968844062237796) },
    { UINT64_C( 5809100127999444266),
      UINT64_C(17936880103521309735),
      UINT64_C( 9053755385840400022) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_x_clmul_u64(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a = simde_test_codegen_random_u64();
    uint64_t b = simde_test_codegen_random_u64();
    uint64_t r = simde_x_clmul_u64(a, b);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_clmulepi64_epi128 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[2];
    const int64_t b[2];
    const int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 1223702322309085129), -INT64_C( 8879567886794638539) },
      {  INT64_C( 7036755598991405826), -INT64_C( 7046740992093250117) },
      {  INT64_C( 2473170614696794478),  INT64_C( 2784948867630424147) } },
    { { -INT64_C( 1917888373892700613),  INT64_C( 8617134813468493061) },
      {  INT64_C(  304687083854804713), -INT64_C( 9179921235781725292) },
      { -INT64_C( 3162169552144031667),  INT64_C(  131895041431953025) } },
    { {  INT64_C( 3393838533477392516), -INT64_C( 6248506160320443813) },
      {  INT64_C( 2728261705044924814), -INT64_C( 1597447023443835378) },
      { -INT64_C( 3677024356011843784),  INT64_C( 1792451366425607224) } },
    { {  INT64_C( 8787708278673885338), -INT64_C( 7121999645218556224) },
      {  INT64_C( 8458129975209667500), -INT64_C( 2907745100206865833) },
      {  INT64_C( 4051687636460756032),  INT64_C( 7169855552534900382) } },
    { { -INT64_C( 4972660111729507483), -INT64_C( 8759108909232666683) },
      { -INT64_C( 8220718353488812785), -INT64_C( 5279645577665465434) },
      {  INT64_C( 4586024153164530195),  INT64_C( 6527978219423536898) } },
    { { -INT64_C( 6168462655054260815),  INT64_C( 1360068410154590078) },
      {  INT64_C( 7897188145811727061), -INT64_C( 9138636182688571098) },
      {  INT64_C( 8359736955429931494),  INT64_C(  444600807865829376) } },
    { {  INT64_C( 2157102855485155168),  INT64_C( 3622676809066638896) },
      {  INT64_C( 7434551563239935736), -INT64_C( 1799456849400005194) },
      {  INT64_C( 7717179827338582336),  INT64_C(  747598803828444825) } },
    { { -INT64_C(  851711651099167885), -INT64_C( 1001364843725806454) },
      { -INT64_C( 2024969269964351683),  INT64_C( 4812501714981208922) },
      {  INT64_C( 3859857334761625956),  INT64_C( 4404639048340928077) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r;

    switch(i & 3) {
      case 0:
        r = simde_mm_clmulepi64_si128(a, b, 0);
        break;
      case 1:
        r = simde_mm_clmulepi64_si128(a, b, 1);
        break;
      case 2:
        r = simde_mm_clmulepi64_si128(a, b, 16);
        break;
      case 3:
        r = simde_mm_clmulepi64_si128(a, b, 17);
        break;
      default:
        HEDLEY_UNREACHABLE();
    }

    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = simde_test_x86_random_i64x2();
    simde__m128i r;

    switch(i & 3) {
      case 0:
        r = simde_mm_clmulepi64_si128(a, b, 0);
        break;
      case 1:
        r = simde_mm_clmulepi64_si128(a, b, 1);
        break;
      case 2:
        r = simde_mm_clmulepi64_si128(a, b, 16);
        break;
      case 3:
        r = simde_mm_clmulepi64_si128(a, b, 17);
        break;
    }

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_clmulepi64_epi128 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[4];
    const int64_t b[4];
    const int64_t r[4];
  } test_vec[] = {
    { { -INT64_C( 8861067646028006915),  INT64_C( 8317570772367584624), -INT64_C( 8479226455593734885),  INT64_C( 4655311630250670693) },
      { -INT64_C(   24828561109850826), -INT64_C( 2740442853538738953),  INT64_C( 6245039060616885418), -INT64_C( 5596787430870122544) },
      { -INT64_C( 3605505260195947138),  INT64_C( 8993753863940455899), -INT64_C( 4734815501727457266),  INT64_C( 2980667195098018359) } },
    { { -INT64_C( 2798286907617568867),  INT64_C( 7052730161524750920),  INT64_C(  562435620224459400),  INT64_C( 4673170309893549227) },
      {  INT64_C( 8305365776004329350),  INT64_C( 8893019314550579025), -INT64_C( 4324931084003054661),  INT64_C(  797917258246198574) },
      {  INT64_C( 7257084772150149552),  INT64_C( 1360287739278401518), -INT64_C( 6290854813130530827),  INT64_C( 3504988492777302678) } },
    { {  INT64_C( 7283082647590633076), -INT64_C( 6790626808863749036), -INT64_C( 6440553767362054461), -INT64_C( 4381007043721983580) },
      { -INT64_C( 5656110618526963961), -INT64_C( 8392532913333670143),  INT64_C( 5660748388734737265), -INT64_C( 7521386788528191859) },
      {  INT64_C( 1518845827335983732),  INT64_C( 3548116382125449697), -INT64_C( 3695683971048001449),  INT64_C( 6487700039540703498) } },
    { {  INT64_C( 8601371122160828753), -INT64_C( 8973451863074711772),  INT64_C( 7996418085041790208),  INT64_C( 7649900638574833409) },
      {  INT64_C( 3951475540046109929),  INT64_C( 1829192730767668173), -INT64_C( 3835451934689210762), -INT64_C( 2328776664548635093) },
      {  INT64_C( 2331280469638464916),  INT64_C(  909250411302452898), -INT64_C( 6456576299602598101),  INT64_C( 3116995424408104456) } },
    { {  INT64_C(  624052268936643937), -INT64_C( 2704049405787911352),  INT64_C( 2642477159451540759), -INT64_C( 1307707947028576508) },
      {  INT64_C( 8439474315985951195),  INT64_C( 7499143535494825940),  INT64_C( 4515407529790423948),  INT64_C(  248844939888759290) },
      {  INT64_C( 9077383510885573499),  INT64_C(  260944091473821904), -INT64_C( 1092040103143313820),  INT64_C(  519807910688705558) } },
    { { -INT64_C( 5562163387622042580), -INT64_C( 9080947942458940096),  INT64_C( 3438692059224424769),  INT64_C( 3597296407246467522) },
      { -INT64_C( 9183020781049018626), -INT64_C( 5154639738173294080), -INT64_C( 1103123323737113012), -INT64_C( 8136941776144800035) },
      { -INT64_C( 7404742307908519552),  INT64_C( 4664504263945087872),  INT64_C( 4990989065081341336),  INT64_C( 1275537234475318560) } },
    { { -INT64_C(  392381640637440051), -INT64_C(  746357658714333324), -INT64_C( 6916359408935577627),  INT64_C( 8191367829375868557) },
      { -INT64_C( 8707415128020215756),  INT64_C( 7298673085559019947),  INT64_C( 8453956785101390063), -INT64_C( 7030048190026754982) },
      {  INT64_C(   41632217925301279),  INT64_C( 2511585804835601581), -INT64_C( 3040775301231111182),  INT64_C( 6698050587281837184) } },
    { { -INT64_C( 6416513484366942376),  INT64_C( 7995090548861593103),  INT64_C( 4855289321808227333), -INT64_C( 8263908277331233721) },
      {  INT64_C( 2469075490216353186), -INT64_C( 8701335448767611566),  INT64_C( 1819126401625972497), -INT64_C( 3059321611736088375) },
      { -INT64_C( 7112732884917849042),  INT64_C( 3926000826017084906),  INT64_C(  606846234052846655),  INT64_C( 8057559887502386125) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi64(test_vec[i].b);
    simde__m256i r;

    switch(i & 3) {
      case 0:
        r = simde_mm256_clmulepi64_epi128(a, b, 0);
        break;
      case 1:
        r = simde_mm256_clmulepi64_epi128(a, b, 1);
        break;
      case 2:
        r = simde_mm256_clmulepi64_epi128(a, b, 16);
        break;
      case 3:
        r = simde_mm256_clmulepi64_epi128(a, b, 17);
        break;
      default:
        HEDLEY_UNREACHABLE();
    }

    simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i b = simde_test_x86_random_i64x4();
    simde__m256i r;

    switch(i & 3) {
      case 0:
        r = simde_mm256_clmulepi64_epi128(a, b, 0);
        break;
      case 1:
        r = simde_mm256_clmulepi64_epi128(a, b, 1);
        break;
      case 2:
        r = simde_mm256_clmulepi64_epi128(a, b, 16);
        break;
      case 3:
        r = simde_mm256_clmulepi64_epi128(a, b, 17);
        break;
    }

    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_clmulepi64_epi128 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[8];
    const int64_t b[8];
    const int64_t r[8];
  } test_vec[] = {
    { { -INT64_C( 4508748162316205256), -INT64_C( 3099372905628098829),  INT64_C( 1016139251664777007),  INT64_C( 4077612542125204877),
        -INT64_C( 5671456079578199782), -INT64_C( 2619368007630660594),  INT64_C( 1145311247069902226), -INT64_C( 6767389031831375652) },
      { -INT64_C( 7502866647642040208), -INT64_C( 4910877245634443694), -INT64_C( 8712927427156658812), -INT64_C( 4787193028275804570),
        -INT64_C( 8992902091992483055),  INT64_C( 3365977461916539858),  INT64_C( 2612731813066721039),  INT64_C( 3547044437640259119) },
      {  INT64_C( 7408876882598746752),  INT64_C( 7975566437154259906), -INT64_C( 7050998394792826820),  INT64_C(  515545422847956525),
         INT64_C(  480365564844410554),  INT64_C( 6443112411602834649),  INT64_C( 8842248389601172078),  INT64_C(  126356363133991767) } },
    { { -INT64_C( 4462225071124306595), -INT64_C(  112462523525131112),  INT64_C( 2133857325112992955), -INT64_C( 5840373422947127646),
         INT64_C( 6101057788694085368), -INT64_C( 7507491933819344413),  INT64_C( 2789888179682970027),  INT64_C( 2114961351064965467) },
      { -INT64_C( 3915684273188333928), -INT64_C( 1040776515624944102), -INT64_C( 6440357149699039500), -INT64_C(  372484428694190190),
        -INT64_C( 6417076916505879999), -INT64_C( 1410985712041489355), -INT64_C( 3838468523262871862), -INT64_C(  438725240223101812) },
      { -INT64_C( 4547041686557986496),  INT64_C( 5174280718535161140), -INT64_C( 4052619716788453016),  INT64_C( 4691236899805083089),
         INT64_C( 2621818318605369123),  INT64_C( 6491826105943833570),  INT64_C( 6742861852404586798),  INT64_C(  659489253161718155) } },
    { {  INT64_C( 7160742299907929903), -INT64_C(  900076532547060322),  INT64_C( 8737198701753722943),  INT64_C( 5008091942838911439),
         INT64_C( 5771750718125940872),  INT64_C( 9185769016342804318),  INT64_C( 1492721472516751952), -INT64_C(  553068161141104649) },
      {  INT64_C( 1350737615534379964),  INT64_C( 6736843039141635263), -INT64_C( 6778390594892172139),  INT64_C( 7050670702599309936),
         INT64_C( 1160958178873018454),  INT64_C( 6745141857603269937), -INT64_C(  626802408982891262),  INT64_C( 6248657622998252976) },
      { -INT64_C( 1487980720625885147),  INT64_C( 2020763090915505301), -INT64_C( 3819958634599510576),  INT64_C( 1236167621747222011),
        -INT64_C( 2121305814586519288),  INT64_C( 1348880127149281018),  INT64_C( 5474740827809109760),  INT64_C(  294120293277450556) } },
    { {  INT64_C( 5015177187211445817),  INT64_C( 4132367358880885043),  INT64_C( 7409040097932578900), -INT64_C( 7744375673736877521),
        -INT64_C( 7542483310570706951),  INT64_C( 5319011699478746720),  INT64_C( 1700661811459962236), -INT64_C( 4426530695618800223) },
      { -INT64_C( 4057705442362544204), -INT64_C( 6109362486595664903), -INT64_C(  944497729116152860), -INT64_C( 6027926296062907443),
         INT64_C( 4853882362087614255), -INT64_C( 3561668997202986057), -INT64_C( 5330150999214821181), -INT64_C( 6535105179831961942) },
      {  INT64_C( 6360605561114465723),  INT64_C( 1874229146988567910), -INT64_C( 7830980124631947605),  INT64_C( 6777172427082462138),
         INT64_C( 6513423505254783264),  INT64_C( 3838992877777853549),  INT64_C( 3476875994488591594),  INT64_C( 8855849316839725126) } },
    { {  INT64_C( 4492507234734576331), -INT64_C( 5473360150391322286), -INT64_C( 3546918803188636377), -INT64_C( 9087772883149647162),
         INT64_C(  330715171927825361), -INT64_C( 7341065912809636999),  INT64_C( 9143275604432054512), -INT64_C( 2037426853844986750) },
      { -INT64_C( 5085177230146187082), -INT64_C( 1613903879242273139),  INT64_C( 3918380942342636586),  INT64_C( 7794648714629225014),
        -INT64_C( 4075403372112025736),  INT64_C(  131556394091910384), -INT64_C( 1616998204104715867), -INT64_C( 7169627097723110049) },
      { -INT64_C( 3555569070185312534),  INT64_C( 1929572009916099035), -INT64_C( 6395368968046142570),  INT64_C( 1709120932256690080),
         INT64_C( 2523358017318337272),  INT64_C(  247934416460539433),  INT64_C(  244155990319815984),  INT64_C( 3215872428597678272) } },
    { { -INT64_C( 8590961978253224507), -INT64_C( 7840127111964488358), -INT64_C( 4993511927647037930),  INT64_C(  664649571826066808),
        -INT64_C( 5925102877851218524), -INT64_C( 7864392723294439589), -INT64_C( 4955067607878416345), -INT64_C(  125379126724457739) },
      {  INT64_C( 8295348044106975774),  INT64_C( 3694526249633119286), -INT64_C( 6386401476306689696),  INT64_C( 7229159512343623164),
        -INT64_C( 4253663533883617684), -INT64_C( 6111460234302671889), -INT64_C( 3263512319597026211),  INT64_C( 2525248044784915809) },
      {  INT64_C( 8089940058166097068),  INT64_C( 4477169705139521861), -INT64_C( 1959136724352530176),  INT64_C(  398152220925199002),
        -INT64_C( 2261768737661003756),  INT64_C( 8063510882445894936),  INT64_C( 8314094987896017049),  INT64_C( 5675994356149893427) } },
    { { -INT64_C( 4442063450844700663), -INT64_C( 1637078751344930479), -INT64_C( 6667107275842742831),  INT64_C( 2674669911162921283),
        -INT64_C( 5346874038663002826),  INT64_C( 5286550275917777639),  INT64_C( 4977438571891807535), -INT64_C( 1563770842758750709) },
      {  INT64_C(  305612682310190883),  INT64_C( 6272622752075124555),  INT64_C( 8174837505515387946),  INT64_C( 3735986652260643385),
        -INT64_C( 2806032233167860500), -INT64_C( 8860928630086400377), -INT64_C( 1982670522702245980), -INT64_C( 1938331273838651947) },
      { -INT64_C( 5520935947472743149),  INT64_C( 4537885097490984960),  INT64_C( 8936024623814528617),  INT64_C( 2290930245258479633),
        -INT64_C( 3134810519185361790),  INT64_C( 6379269477255759439),  INT64_C( 7072358411685850147),  INT64_C( 4195183069244768317) } },
    { {  INT64_C( 6042983852705567862), -INT64_C( 4223521988775085949),  INT64_C(  965824450707592408),  INT64_C( 6359096840191948897),
        -INT64_C( 5764827233489571872), -INT64_C( 2047185047042326096),  INT64_C( 1462207194453140997),  INT64_C( 2972568486031604998) },
      { -INT64_C( 8882271837156434977),  INT64_C( 4522998559612946646), -INT64_C(  137423594610545839),  INT64_C( 1546465536708609539),
        -INT64_C(  713298132974154814), -INT64_C( 6153153657742856668), -INT64_C( 2396541879086868794), -INT64_C( 8316000295776967604) },
      {  INT64_C( 6427478446298047098),  INT64_C( 1161562776606732481),  INT64_C( 4521385688827072163),  INT64_C(  334400680930988147),
         INT64_C( 2179120516870574272),  INT64_C( 7717920184672985687), -INT64_C( 7275182691465067096),  INT64_C( 1538449054100258674) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__m512i r;

    switch(i & 3) {
      case 0:
        r = simde_mm512_clmulepi64_epi128(a, b, 0);
        break;
      case 1:
        r = simde_mm512_clmulepi64_epi128(a, b, 1);
        break;
      case 2:
        r = simde_mm512_clmulepi64_epi128(a, b, 16);
        break;
      case 3:
        r = simde_mm512_clmulepi64_epi128(a, b, 17);
        break;
      default:
        HEDLEY_UNREACHABLE();
    }

    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__m512i b = simde_test_x86_random_i64x8();
    simde__m512i r;

    switch(i & 3) {
      case 0:
        r = simde_mm512_clmulepi64_epi128(a, b, 0);
        break;
      case 1:
        r = simde_mm512_clmulepi64_epi128(a, b, 1);
        break;
      case 2:
        r = simde_mm512_clmulepi64_epi128(a, b, 16);
        break;
      case 3:
        r = simde_mm512_clmulepi64_epi128(a, b, 17);
        break;
    }

    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(x_clmul_u64)

//  SIMDE_TEST_FUNC_LIST_ENTRY(mm_clmulepi64_epi128)
//  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_clmulepi64_epi128)
//  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_clmulepi64_epi128)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/test-x86-footer.h>
