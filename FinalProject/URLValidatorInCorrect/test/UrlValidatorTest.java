/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


import junit.framework.TestCase;

import java.util.Random;


/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest extends TestCase {

   private boolean printStatus = false;
   private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(urlVal.isValid("http://www.amazon.com"));
	   
   }
   
   
   public void testYourFirstPartition()
   {
	   
   }
   
   public void testYourSecondPartition(){
	   
   }
   
   
   public void testIsValid()
   {
       UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       Random random = new Random();
       String[] invalidSchemes = getInvalidSchemes();
       String[] validHosts = getValidHosts();
       String[] invalidHosts = getInvalidHosts();
       String[] validSchemes = getValidSchemes();
       // test with invalid schemes
       for (int i = 0; i < 5000; i++) {
           int randomIdxHost = random.nextInt(validHosts.length);
           int randomIdxScheme = random.nextInt(invalidSchemes.length);
           //System.out.println(randomIdx);
           String url = invalidSchemes[randomIdxScheme] + validHosts[randomIdxHost];
           //System.out.println(url);
           assertFalse(urlValidator.isValid(url));
           // test with invalid hosts
           randomIdxScheme = random.nextInt(validSchemes.length);
           randomIdxHost = random.nextInt(invalidHosts.length);
           url = invalidHosts[randomIdxHost] + validSchemes[randomIdxScheme];
           assertFalse(urlValidator.isValid(url));
           // test with valid scheme and valid host
           randomIdxScheme = random.nextInt(validSchemes.length);
           randomIdxHost = random.nextInt(validHosts.length);
           url = validSchemes[randomIdxScheme] + validHosts[randomIdxHost];
           assertTrue(urlValidator.isValid(url));
           // test with invalid paths
           String[] invalidPaths = getInvalidPaths();
           randomIdxScheme = random.nextInt(validSchemes.length);
           int randomIdxPath = random.nextInt(invalidPaths.length);
           url = validSchemes[randomIdxScheme] + invalidPaths[randomIdxPath];
           assertFalse(urlValidator.isValid(url));
           // test with valid paths
           String[] validPaths = getValidPaths();
           randomIdxPath = random.nextInt(validPaths.length);
           url = validSchemes[randomIdxScheme] + validHosts[randomIdxHost] + validPaths[randomIdxPath];
           assertTrue(urlValidator.isValid(url));
       }
   }
   
   public void testAnyOtherUnitTest()
   {
	   
   }

    public String[] getInvalidSchemes() {
       String[] schemes = {"boom//", "htp:/", "htps//", "1ttt://"};
       return schemes;
    }

    public String[] getValidSchemes() {
       String[] schemes = {"http://", "ftp://", "https://", "boom://"};
       return schemes;
    }

    public String[] getValidHosts() {
       String[] hosts = {"google.com", "apple.com", "www.osu.org"};
       return hosts;
    }

    public String[] getInvalidHosts() {
       String[] hosts = {"aaa", "bbb", "123", "1.2.3.4"};
       return hosts;
    }

    public String[] getInvalidPaths() {
       String[] paths = {"/test//", "../test", "..."};
       return paths;
    }

    public String[] getValidPaths() {
       String[] paths = {"", "/test/", "/test/foo"};
       return paths;
    }

   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */


}
