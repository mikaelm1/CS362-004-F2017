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
       // test with invalid schemes
       for (int i = 0; i<invalidSchemes.length; i++) {
            int randomIdx = random.nextInt(validHosts.length);
           //System.out.println(randomIdx);
           String url = invalidSchemes[i] + validHosts[randomIdx];
           //System.out.println(url);
           assertFalse(urlValidator.isValid(url));
       }
       String[] invalidHosts = getInvalidHosts();
       String[] validSchemes = getValidSchemes();
       // test with invalid hosts
       for (int i = 0; i < invalidHosts.length; i++) {
           int randomIdx = random.nextInt(validSchemes.length);
           String url = invalidHosts[i] + validSchemes[randomIdx];
           assertFalse(urlValidator.isValid(url));
       }
       // test with valid schemes and hosts
       for (int i = 0; i < validSchemes.length; i++) {
           for (int j = 0; j < validHosts.length; j++) {
               String url = validSchemes[i] + validHosts[j];
               assertTrue(urlValidator.isValid(url));
           }
       }
       // test with invalid paths
       String[] invalidPaths = getInvalidPaths();
       for (int i = 0; i < invalidPaths.length; i++) {
           String url = validSchemes[0] + validHosts[0] + invalidPaths[i];
           assertFalse(urlValidator.isValid(url));
       }
       // test with valid paths
       String[] validPaths = getValidPaths();
       for (int i = 0; i < validPaths.length; i++) {
           String url = validSchemes[0] + validHosts[0] + validPaths[i];
           assertTrue(urlValidator.isValid(url));
       }
   }
   
   public void testAnyOtherUnitTest()
   {
	   
   }

    public String[] getSchemes() {
        String[] schemes = {"http://", "https://"};
        return schemes;
    }

    public String[] getInvalidSchemes() {
       String[] schemes = {"boom//", "htp:/", "htps//", "1ttt://"};
       return schemes;
    }

    public String[] getValidSchemes() {
       String[] schemes = {"http://", "ftp://", "https://"};
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
